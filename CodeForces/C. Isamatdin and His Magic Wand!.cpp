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
      vector<int> arr(n);

      vector<int> even;
      vector<int> odd;

      for (int i = 0; i < n; ++i)
      {
         cin >> arr[i];
         if (arr[i] % 2 == 0)
            even.push_back(arr[i]);
         else
            odd.push_back(arr[i]);
      }

      if (even.empty() || odd.empty())
      {
         for (int i = 0; i < n; ++i)
         {
            cout << arr[i] << " ";
         }
         cout << '\n';
      }
      else
      {
         sort(arr.begin(), arr.end());
         for (int i = 0; i < n; ++i)
         {
            cout << arr[i] << " ";
         }
         cout << '\n';
      }
   }

   return 0;
}