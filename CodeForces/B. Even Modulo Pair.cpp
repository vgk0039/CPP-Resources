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
      for (int i = 0; i < n; ++i)
      {
         cin >> arr[i];
      }

      bool found = false;

      for (int i = 0; i < n; ++i)
      {
         for (int j = i + 1; j < n; ++j)
         {
            if (arr[i] == 0)
               continue;
            int p = arr[j] % arr[i];
            if (p % 2 == 0)
            {
               cout << arr[i] << " " << arr[j] << endl;
               found = true;
               break;
            }
         }
         if (found)
            break;
      }

      if (!found)
         cout << "-1" << endl;
   }

   return 0;
}