#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void solve()
{
   long long n;
   int d;
   std::cin >> n >> d;

   std::vector<int> divisors;
   divisors.push_back(1);
   if (n >= 3 || (n == 2 && d % 3 == 0))
   {
      divisors.push_back(3);
   }
   if (d == 5)
   {
      divisors.push_back(5);
   }
   if (n >= 3 || (n == 2 && d == 7))
   {
      divisors.push_back(7);
   }
   bool is_divisible_by_9 = false;
   if (n >= 6)
   {
      is_divisible_by_9 = true;
   }
   else if (n >= 3)
   {
      if (d % 3 == 0)
      {
         is_divisible_by_9 = true;
      }
   }
   else
   {
      if (d == 9)
      {
         is_divisible_by_9 = true;
      }
   }
   if (is_divisible_by_9)
   {
      divisors.push_back(9);
   }
   for (size_t i = 0; i < divisors.size(); ++i)
   {
      std::cout << divisors[i] << (i == divisors.size() - 1 ? "" : " ");
   }
   std::cout << std::endl;
}

int main()
{
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(NULL);

   int t;
   std::cin >> t;
   while (t--)
   {
      solve();
   }

   return 0;
}