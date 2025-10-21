// 30-05-2025

#include <iostream>
#include <math.h>
#include <climits> //For range functions
// or we can just add
#include <bits/stdc++.h>
// This means adding literally everything. Leaves out very few things
using namespace std;
int main()
{
   int intnum = INT_MIN; // 10^9
   cout << intnum << endl;
   cout << "Hello!" << endl;

   long numlong = LONG_MAX; // 10^12
   cout << numlong << endl;
   float numfloat = 10.5; // Prescission of 7 decimal places

   char ch = '&';
   cout << ch << endl;
   int bdate, checknum;
   cin >> bdate >> checknum;
   cout << bdate << endl
        << checknum << endl;
   // String is a class under namespace
   /*If we didn't use namespace std in the beginning we have to write as
             std::string instead of just string*/
   string game = "Chess";
   cout << game << endl;
   string teststring;
   cin >> teststring;
   cout << teststring << endl;
   cin.ignore();
   /*This isAfter reading teststring with cin,
    the newline character remains in the input buffer.
    Before getline(), cin.ignore() clears it so that getline() works properly.
   */
   // string class doesn't take white spaces.If we want to take whole line as an input we have to do this:
   string goatplayer1,goatplayer2;
   getline(cin, goatplayer1);
   getline(cin,goatplayer2);
   cout << goatplayer1 << endl<<goatplayer2<<endl;
 for (int i = 0; i < 10; i++)
 {
   cout<<"Zoro"<<endl;
 }

 int num[5] = {1,5,7,4,9};
 cout<<num[2]<<endl;
 for (int i = 0; i <5; i++)
 {
   cout<<num[i]<<endl;
 }

 string str1 ("Kuma and Nami");
 cout<<str1<<endl;
 
 


   return 0;
}
