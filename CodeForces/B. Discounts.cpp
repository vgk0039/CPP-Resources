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
      int n, k;
      cin >> n >> k;
      vector<long long> price(n);
      vector<int> discount(k);

      for (int i = 0; i < n; ++i)
      {
         cin >> price[i];
      }
      for (int i = 0; i < k; ++i)
      {
         cin >> discount[i];
      }

      sort(price.rbegin(), price.rend());
      sort(discount.begin(), discount.end());

      long long toPay = 0;
      int item_ptr = 0;

      for (int x : discount)
      {
         if (item_ptr >= n)
         {
            break;
         }

         if (x == 1)
         {
            item_ptr++;
         }
         else
         {
            for (int i = 0; i < x - 1; ++i)
            {
               if (item_ptr < n)
               {
                  toPay += price[item_ptr];
                  item_ptr++;
               }
            }
            if (item_ptr < n)
            {
               item_ptr++;
            }
         }
      }

      while (item_ptr < n)
      {
         toPay += price[item_ptr];
         item_ptr++;
      }

      cout << toPay <<endl;
   }

   return 0;
}