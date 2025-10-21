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
      long long a, b;
      cin >> a >> b;
      long long maxEven = -1;

      for (long long i = 1; i * i <= b; ++i)
      {
         if (b % i == 0)
         {

            long long k1 = i;
            long long a1 = a * k1;
            long long b1 = b / k1;
            if ((a1 + b1) % 2 == 0)
               maxEven = max(maxEven, a1 + b1);
            long long k2 = b / i;
            if (k1 != k2)
            {
               long long a2 = a * k2;
               long long b2 = b / k2;
               if ((a2 + b2) % 2 == 0)
                  maxEven = max(maxEven, a2 + b2);
            }
         }
      }

      cout << maxEven << '\n';
   }

   return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     if (!(cin >> t)) return 0;
//     while (t--) {
//         long long a, b;
//         cin >> a >> b;
//         int r = 0;
//         long long temp = b;
//         while ((temp % 2LL) == 0) {
//             temp /= 2LL;
//             ++r;
//         }
//         // temp is m (odd part)
//         long long ans_ll = -1;

//         if (r == 0) {
//             // b is odd
//             if (a % 2 == 1) {
//                 __int128 val = (__int128)a * (__int128)b + 1;
//                 ans_ll = (long long)val;
//             } else {
//                 ans_ll = -1;
//             }
//         } else if (r == 1) {
//             // b has exactly one factor of 2
//             if (a % 2 == 1) {
//                 ans_ll = -1;
//             } else {
//                 // choose k = b/2 => q = 2
//                 __int128 val = (__int128)a * (__int128)(b / 2) + 2;
//                 ans_ll = (long long)val;
//             }
//         } else {
//             // r >= 2 : choose k = b/2 => q = 2 works for both parities of a
//             __int128 val = (__int128)a * (__int128)(b / 2) + 2;
//             ans_ll = (long long)val;
//         }

//         cout << ans_ll << '\n';
//     }
//     return 0;
// }
