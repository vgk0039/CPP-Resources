#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int ans = n % 3;
      if (ans == 1)
         cout << 2 << endl;
      else if (ans == 2)
         cout << 1 << endl;

      else
         cout << 0 << endl;
   }

   return 0;
}