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

      long long n, x;
      cin >> n >> x;
      vector<long long> arr;
      arr.push_back(0);
      for (int i = 0; i < n; i++)
      {
         long long point;
         cin >> point;
         arr.push_back(point);
      }
      arr.push_back(x);
      n = arr.size();

      long long maxDis = INT_MIN;
      for (int i = 1; i < n; i++)
      {
         if (i == n - 1)
            maxDis =
                max(maxDis, 2 * (arr[i] - arr[i - 1]));
         else
            maxDis =
                max(maxDis, arr[i] - arr[i - 1]);
      }
      cout << maxDis << endl;
   }

   return 0;
}