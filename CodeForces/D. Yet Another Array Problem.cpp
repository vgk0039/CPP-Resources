#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t;
   cin >> t;

   vector<long long> Primes = {
       2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
       31, 37, 41, 43, 47, 53, 59, 61, 67,
       71, 73, 79, 83, 89, 97};

   while (t--)
   {
      int n;
      cin >> n;

      vector<long long> arr(n);
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }

      long long ans = -1;

      for (long long i : Primes)
      {
         bool sab = true;
         int j = 0;
         while (j < n)
         {
            if (arr[j] % i != 0)
            {
               sab = false;
               break;
            }
            ++j;
         }

         if (!sab)
         {
            ans = i;
            break;
         }
      }

      cout << ans << "\n";
   }

   return 0;
}