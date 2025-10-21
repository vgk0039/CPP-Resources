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
      vector<long long> field(n);
      long long totalSum = 0;
      int oddCount = 0;
      long long minOdd = LLONG_MAX;

      for (int i = 0; i < n; ++i)
      {
         cin >> field[i];
         totalSum += field[i];
         if (field[i] % 2 != 0)
         {
            oddCount++;
            minOdd = min(minOdd, field[i]);
         }
      }

      if (oddCount == 0)
      {
         cout << 0 << "\n";
      }
      else if (oddCount % 2 == 1)
      {
         cout << totalSum << "\n";
      }
      else
      {
         cout << totalSum - minOdd << "\n";
      }
   }
   return 0;
}
