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
      int n, m;
      string a, b, c;
      cin >> n >> a >> m >> b >> c;
      string pref = "", suff = "";
      for (int i = 0; i < m; ++i) {
            if (c[i] == 'V') pref = b[i] + pref;
            else suff += b[i];
        }

      cout << pref + a + suff << '\n';
   }

   return 0;
}