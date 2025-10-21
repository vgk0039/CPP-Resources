#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   string s;
   cin >> s;
   set<char> charSet;
   for (char ch : s)
   {
      charSet.insert(ch);
   }

   if (charSet.size() % 2 == 0)

      cout << "CHAT WITH HER!";
   else
      cout << "IGNORE HIM!";

   return 0;
}