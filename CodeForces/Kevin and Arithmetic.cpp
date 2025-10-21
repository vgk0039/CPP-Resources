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
      int sum = 0, points = 0;
      int n;
      cin >> n;
      vector<int> nums(n);
      for (int i = 0; i < n; ++i)
      {
         cin >> nums[i];
      }
      vector<int> reordered;
      for (int x : nums)
         if (x % 2 == 0)
            reordered.push_back(x);
      for (int x : nums)
         if (x % 2 == 1)
            reordered.push_back(x);
      nums = move(reordered);

      for (int i = 0; i < n; ++i)
      {
         sum += nums[i];
         if (sum % 2 == 0)
         {
            points++;
            sum >>= __builtin_ctz(sum);
         }
      }

      cout << points << '\n';
   }

   return 0;
}