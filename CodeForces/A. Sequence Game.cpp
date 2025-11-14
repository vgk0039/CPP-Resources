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
      int n, x;
      cin >> n;
      vector<int> arr(n);
      for (int i = 0; i < n; ++i)
      {
         cin >> arr[i];
      }
      cin >> x;

      int minVal = *min_element(arr.begin(), arr.end());
      int maxVal = *max_element(arr.begin(), arr.end());

      cout << ((minVal <= x && x <= maxVal) ? "YES" : "NO") << endl;
   }

   return 0;
}