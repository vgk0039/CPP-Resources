#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    cin >> word;

    int countUpper = 0, countLower = 0;
    for (char ch : word)
    {
        if (isupper(ch))
            countUpper++;
        else
            countLower++;
    }

    if (countUpper > countLower)
        transform(word.begin(), word.end(), word.begin(), ::toupper);
    else
        transform(word.begin(), word.end(), word.begin(), ::tolower);

    cout << word << '\n';
    return 0;
}