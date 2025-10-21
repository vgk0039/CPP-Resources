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
      string word;
      cin>>word;
      int n = word.size();
      if (n <= 10)
      {
         cout<<word<<endl;
      }
      else{
         cout<<word[0]<<n-2<<word[n-1]<<endl;
      }
      
     
   }

   return 0;
}