#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string binary;
    cin >> binary;

    int count = 1; 
    for (int i = 1; i < binary.size(); ++i)
    {
        if (binary[i] == binary[i - 1])
        {
            count++;
            if (count >= 7)
            {
                cout << "YES\n";
                return 0;
            }
        }
        else
        {
            count = 1; // Reset count on change
        }
    }

    cout << "NO\n";
    return 0;
}