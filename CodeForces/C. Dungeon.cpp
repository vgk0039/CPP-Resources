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
      cin >> n >> m;
      vector<int> a(n);
      vector<int> b(m);
      vector<int> c(m);

      for (auto &x : a)
         cin >> x;
      for (auto &x : b)
         cin >> x;
      for (auto &x : c)
         cin >> x;
      vector<pair<int, int>> nonZeroM;
      vector<int> zeroM;

      for (int i = 0; i < m; i++)
      {
         if (c[i] > 0)
         {
            nonZeroM.push_back({b[i], c[i]});
         }
         else
         {
            zeroM.push_back(b[i]);
         }
      }

      sort(nonZeroM.begin(), nonZeroM.end());
      sort(zeroM.begin(), zeroM.end());

      multiset<int> s(a.begin(), a.end());
      int count = 0;
      for (auto [life, reward] : nonZeroM)
      {
         auto it = s.lower_bound(life);

         if (it == s.end())
            continue;

         count++;
         int sword_used = *it;
         s.erase(it);

         s.insert(max(sword_used, reward));
      }

      for (int life : zeroM)
      {

         auto it = s.lower_bound(life);

         if (it == s.end())
            continue;

         count++;
         s.erase(it);
      }

      cout << count << endl;
   }

   return 0;
}