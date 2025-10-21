#include <bits/stdc++.h>
using namespace std;

int main()
{
   // Example 1: Using a simple array-based hash table (count frequency of integers)
   int arr[] = {5, 6, 5, 6, 9, 6};
   int n = 6;
   int hashTable[10] = {0}; // assuming elements are in range 0-9

   for (int i = 0; i < n; i++)
   {
      hashTable[arr[i]]++;
   }

   cout << "Using array-based hash table:\n";
   for (int i = 0; i < 10; i++)
   {
      if (hashTable[i] > 0)
         cout << i << " occurs " << hashTable[i] << " times\n";
   }

   // Example 2: Using unordered_map (more flexible and powerful)
   unordered_map<int, int> hashMap;

   for (int i = 0; i < n; i++)
   {
      hashMap[arr[i]]++;
   }

   cout << "\nUsing unordered_map:\n";
   for (auto pair : hashMap)
   {
      cout << pair.first << " occurs " << pair.second << " times\n";
   }

   return 0;
}
