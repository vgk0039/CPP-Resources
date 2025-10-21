#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      long long c;
      cin >> n >> c;
      vector<long long> bags(n);
      for (int i = 0; i < n; ++i)
      {
         cin >> bags[i];
      }
      int coins = 0;
      while (!bags.empty())
      {
         int toDelete = -1;
         long long bestWeight = -1;
         for (int i = 0; i < bags.size(); ++i)
         {
            if (bags[i] <= c && bags[i] > bestWeight)
            {
               bestWeight = bags[i];
               toDelete = i;
            }
         }
         if (toDelete == -1)
         {
            toDelete = min_element(bags.begin(), bags.end()) - bags.begin();
            coins++;
         }
         bags.erase(bags.begin() + toDelete);
         for (auto &weight : bags)
         {
            weight *= 2;
         }
      }
      cout << coins << '\n';
   }
   return 0;
}