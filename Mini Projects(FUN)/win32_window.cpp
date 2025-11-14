#include <windows.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
const int BLOCK_SIZE = 20;
const int GRID_WIDTH = 30;
const int GRID_HEIGHT = 20;
const int GAME_TIMER_ID = 1;
const int INITIAL_GAME_SPEED = 150;
const int WINDOW_WIDTH = BLOCK_SIZE * GRID_WIDTH;
const int WINDOW_HEIGHT = BLOCK_SIZE * GRID_HEIGHT;

std::vector<POINT> snakeBody;
POINT food;
int direction;
int score;
bool gameOver;
int gameSpeed;
HBRUSH hBkgBrush;
HBRUSH hSnakeBrush;
HBRUSH hFoodBrush;
HFONT hFont;

void SetupGame();
void SpawnFood();
void UpdateGame(HWND hwnd);
void DrawGame(HDC hdc);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/**
 * @brief Resets the game to its initial state
 */
void SetupGame()
{
    snakeBody.clear();
    snakeBody.push_back({GRID_WIDTH / 2, GRID_HEIGHT / 2});
    snakeBody.push_back({(GRID_WIDTH / 2) - 1, GRID_HEIGHT / 2});
    snakeBody.push_back({(GRID_WIDTH / 2) - 2, GRID_HEIGHT / 2});

    direction = 0;
    score = 0;
    gameOver = false;
    gameSpeed = INITIAL_GAME_SPEED;

    SpawnFood();
}

/**
 * @brief Spawns food in a random location not on the snake
 */
void SpawnFood()
{
    bool onSnake;
    do
    {
        onSnake = false;
        food.x = rand() % GRID_WIDTH;
        food.y = rand() % GRID_HEIGHT;
        for (const auto &segment : snakeBody)
        {
            if (food.x == segment.x && food.y == segment.y)
            {
                onSnake = true;
                break;
            }
        }
    } while (onSnake);
}

/**
 * @brief The main game logic update, called by the timer
 */
void UpdateGame(HWND hwnd)
{
    if (gameOver)
    {
        return;
    }

    POINT newHead = snakeBody.front();
    switch (direction)
    {
    case 0:
        newHead.x++;
        break;
    case 1:
        newHead.y++;
        break;
    case 2:
        newHead.x--;
        break;
    case 3:
        newHead.y--;
        break;
    }
    if (newHead.x < 0 || newHead.x >= GRID_WIDTH ||
        newHead.y < 0 || newHead.y >= GRID_HEIGHT)
    {
        gameOver = true;
    }
    for (size_t i = 1; i < snakeBody.size(); ++i)
    {
        if (newHead.x == snakeBody[i].x && newHead.y == snakeBody[i].y)
        {
            gameOver = true;
            break;
        }
    }

    if (gameOver)
    {
        KillTimer(hwnd, GAME_TIMER_ID);
        MessageBox(hwnd, "Game Over!\nPress 'R' to Restart.", "Snake", MB_OK);
        return;
    }

    snakeBody.insert(snakeBody.begin(), newHead);

    if (newHead.x == food.x && newHead.y == food.y)
    {
        score += 10;
        SpawnFood();

        if (gameSpeed > 50)
        {
            gameSpeed -= 5;
            KillTimer(hwnd, GAME_TIMER_ID);
            SetTimer(hwnd, GAME_TIMER_ID, gameSpeed, NULL);
        }
    }
    else
    {
        snakeBody.pop_back(); // Remove tail
    }

    InvalidateRect(hwnd, NULL, FALSE);
}

/**
 * @brief Handles all drawing inside the WM_PAINT message
 */
void DrawGame(HDC hdc)
{
    RECT clientRect;
    GetClientRect(WindowFromDC(hdc), &clientRect);
    HDC memDC = CreateCompatibleDC(hdc);
    HBITMAP hBmp = CreateCompatibleBitmap(hdc, clientRect.right, clientRect.bottom);
    HBITMAP hOldBmp = (HBITMAP)SelectObject(memDC, hBmp);

    FillRect(memDC, &clientRect, hBkgBrush);

    RECT foodRect = {
        food.x * BLOCK_SIZE,
        food.y * BLOCK_SIZE,
        (food.x + 1) * BLOCK_SIZE,
        (food.y + 1) * BLOCK_SIZE};
    FillRect(memDC, &foodRect, hFoodBrush);

    for (const auto &segment : snakeBody)
    {
        RECT segmentRect = {
            segment.x * BLOCK_SIZE,
            segment.y * BLOCK_SIZE,
            (segment.x + 1) * BLOCK_SIZE,
            (segment.y + 1) * BLOCK_SIZE};
        FillRect(memDC, &segmentRect, hSnakeBrush);
    }
    std::string scoreText = "Score: " + std::to_string(score);
    SetTextColor(memDC, RGB(255, 255, 255));
    SetBkMode(memDC, TRANSPARENT);
    SelectObject(memDC, hFont);
    RECT scoreRect = {5, 5, 200, 50};
    DrawText(memDC, scoreText.c_str(), -1, &scoreRect, DT_TOP | DT_LEFT);
    if (gameOver)
    {
        const char *GO_TEXT = "Game Over!\nPress 'R' to Restart";
        SetTextColor(memDC, RGB(255, 0, 0));
        DrawText(memDC, GO_TEXT, -1, &clientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }

    BitBlt(hdc, 0, 0, clientRect.right, clientRect.bottom, memDC, 0, 0, SRCCOPY);
    SelectObject(memDC, hOldBmp);
    DeleteObject(hBmp);
    DeleteDC(memDC);
}

/**
 * @brief The main Window Procedure (handles all messages)
 */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

    case WM_CREATE:
    {

        hBkgBrush = CreateSolidBrush(RGB(20, 20, 40));
        hSnakeBrush = CreateSolidBrush(RGB(0, 255, 0));
        hFoodBrush = CreateSolidBrush(RGB(255, 0, 0));

        hFont = CreateFont(20, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                           DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                           DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
        srand(static_cast<unsigned>(time(0)));

        SetupGame();

        SetTimer(hwnd, GAME_TIMER_ID, gameSpeed, NULL);
        return 0;
    }

    case WM_TIMER:
    {
        if (wParam == GAME_TIMER_ID)
        {
            UpdateGame(hwnd);
        }
        return 0;
    }
    case WM_KEYDOWN:
    {
        switch (wParam)
        {
        case VK_UP:
        case 'W':
            if (direction != 1)
                direction = 3;
            break;
        case VK_DOWN:
        case 'S':
            if (direction != 3)
                direction = 1;
            break;
        case VK_LEFT:
        case 'A':
            if (direction != 0)
                direction = 2;
            break;
        case VK_RIGHT:
        case 'D':
            if (direction != 2)
                direction = 0;
            break;
        case 'R':
            if (gameOver)
            {
                SetupGame();
                SetTimer(hwnd, GAME_TIMER_ID, gameSpeed, NULL); // Restart timer
            }
            break;
        }
        return 0;
    }

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        DrawGame(hdc);

        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_DESTROY:
    {

        KillTimer(hwnd, GAME_TIMER_ID);
        DeleteObject(hBkgBrush);
        DeleteObject(hSnakeBrush);
        DeleteObject(hFoodBrush);
        DeleteObject(hFont);

        PostQuitMessage(0);
        return 0;
    }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

/**
 * @brief The main entry point for a Windows GUI application
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const char CLASS_NAME[] = "SnakeWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;

    RegisterClass(&wc);

    RECT windowRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    AdjustWindowRect(&windowRect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, FALSE);
    int adjWidth = windowRect.right - windowRect.left;
    int adjHeight = windowRect.bottom - windowRect.top;
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Win32 Snake Game",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, // Non-resizable style

        CW_USEDEFAULT, CW_USEDEFAULT,

        adjWidth, adjHeight,

        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
