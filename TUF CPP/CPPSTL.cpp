#include <bits/stdc++.h>
using namespace std;

void ExplainPair()
{ /*In C++, a pair is a simple container provided by the Standard Template Library (STL)
    to store two related values (not necessarily of the same type)
    as a single unit.*/
   //-------SYNTAX--------
   /*
   #include <utility>  // Required for std::pair
      using namespace std;

      pair<data_type1, data_type2> pair_name;
   */
   pair<int, int> pr1 = {3, 9}; // We can do it with the following function aswell
   pair<int, string> student = make_pair(1, "Chinna");
   pair<int, string> p1(1, "Apple"); // Constructor
   cout << p1.first << " , " << p1.second << endl;
   cout << pr1.first << " " << pr1.second << endl;

   // Nested Pairs
   pair<int, pair<int, int>> p = {1, {2, 3}};

   cout << "First: " << p.first << endl;
   cout << "Second First: " << p.second.first << endl;
   cout << "Second Second: " << p.second.second << endl;
}

void ExplainVector()
{
   /*A vector in C++ STL is a dynamic array that can grow or
   shrink in size automatically. It's part of the <vector> header*/
   //----------SYNTAX---------
   /*
   #include <vector>
     using namespace std;

     vector<datatype> vec;
   */
   vector<int> numbers;          // Empty vector of integers
   vector<string> names(5);      // Vector of 5 strings initialized to ""
   vector<int> nums = {1, 2, 3}; // Initializing directly

   vector<int> Vec = {6, 9};
   Vec.push_back(1);
   Vec.push_back(2);
   Vec.emplace_back(0); // Two ways to do it

   for (int i = 0; i < Vec.size(); i++)
   {
      cout << Vec[i] << " ";
   }
   cout << endl;
   // Another way to iterate through Vectors is
   vector<int>::iterator beginitr = Vec.begin();
   cout << *beginitr << endl;
   auto enditr = Vec.end(); // It will not point to last element rather than it will point to location next to last element location

   // It basically return us the pointer to the memory location of the first element of the vector.
   // It is reffering to the memory location of the first element.

   for (vector<int>::iterator /*auto*/ i = beginitr; i < enditr; i++)
   {
      cout << *i << " ";
   }
   //-----------OR we can do---------
   for (auto i : Vec)
   {
      cout << i << " ";
   }
   cout << endl;
   auto reversebegin = Vec.rbegin(); // Pointing to last element
   auto reverseend = Vec.rend();     // Pont to somewhere before begining
   for (auto i = reversebegin; i < reverseend; i++)
   {
      cout << *i << " ";
   }
   cout << endl;
   cout << Vec.front() << endl; // Gives first element
   cout << Vec.back() << endl;
   Vec.pop_back(); // Pops last element
   swap(nums, Vec);
   for (auto i : Vec)
   {
      cout << i << " ";
   }
   cout << endl;
   //-------Insert-------
   vector<int> tst = {5, 4, 7, 9, 8};
   tst.insert(tst.begin() + 2, 0);
   for (auto i : tst)
   {
      cout << i << " ";
   }
   cout << endl;
}
void ExplainList()
{
   // Mostly similar to vectors
   list<int> Lst = {6, 7};
   Lst.push_front(5);
   for (auto i : Lst)
   {
      cout << i << " ";
   }
   cout << endl;
}
void ExplainStack()
{
   // LIFO
   stack<int> st;
   st.push(6);
   st.push(9);
   st.push(5);
   st.push(2);
   st.push(4);
   st.push(0);
   cout << st.size() << endl;
   cout << st.top() << endl;
   st.pop();
   cout << st.top() << endl;
   while (st.empty() == false)
   {
      cout << st.top() << " ";
      st.pop();
   }
   cout << endl;
}
void ExplainQueue()
{

   // FIFO
   queue<int> q;
   q.push(4);
   q.push(6);
   q.push(9);
   q.push(7);
   q.push(5);
   while (q.empty() == false)
   {
      cout << q.front() << " ";
      q.pop();
   }
   cout << endl;
}
void ExplainPQ()
{

   // Stores  the highest element at the top
   priority_queue<int> pq;
   pq.push(4);
   pq.push(6);
   pq.push(9);
   pq.push(7);
   pq.push(5);
   while (pq.empty() == false)
   {
      cout << pq.top() << " ";
      pq.pop();
   }
   cout << endl;
   // We can do it in descending order as well
}
void ExplainSet()
{
   // Stores only unique elements and in ascending order
   set<int> st;
   st.insert(6);
   st.insert(9);
   st.insert(8);
   st.insert(6);
   st.insert(4);
   st.insert(11);
   st.insert(2);
   st.insert(88);

   for (auto i : st)
   {
      cout << i << " ";
   }
   cout << endl;
   auto it1 = st.find(8);
   if (it1 != st.end())
   {
      cout << *it1;
   }
   cout << endl;
   cout << st.count(8); // Instead of find use it to check if it is present in set or not
   // If the element is present it will output 1 else it will out put 0.
   st.erase(9);
   cout << endl;
   for (auto i : st)
   {
      cout << i << " ";
   }
   cout << endl;
   // We can delete any element at any position
   auto iter1 = st.begin();
   iter1++;
   auto iter2 = st.end();
   iter2--;
   st.erase(iter1, iter2);
   for (auto x : st)
   {
      cout << x << " ";
   }
   cout << endl;
   // Lower bound returns an iterator that points to an element that is greater tha equa to the number given
   auto lb = st.lower_bound(8);
   if (lb != st.end())
   {
      cout << *lb;
   }
   cout << endl;
}
void ExplainMultiSet()
{
   // Same like Set But also stores repeating(duplicate) elements aswell
   multiset<int> mst;
   // Are al the functionalities same ?? No
   mst.insert(6);
   mst.insert(9);
   mst.insert(88);
   mst.insert(6);
   mst.insert(4);
   mst.insert(11);
   mst.insert(2);
   mst.insert(88);

   auto it2 = mst.erase(mst.find(88));

   for (auto it : mst)
   {
      cout << it << " ";
   }
   cout << endl;
}
void ExplainMap()
{
   /*
   A map is a sorted associative container that stores elements in key-value pairs.
Each key is unique, and it's always sorted in ascending order.*/

   //---------SYNTAX----------
   /*
   map<key_type, value_type> map_name;
   */

   map<int, string> mp;
   mp.insert({4, "AS"});
   mp[1] = "JP";
   mp[2] = "PU";
   mp[3] = "VGK";

   for (auto it : mp)
   {
      cout << it.first << "-->" << it.second << endl;
   }
   // Unique keys and sorted
   auto p = mp.find(4);
   cout << (*p).first << "-->" << (*p).second << endl;

   // It will always return a pointer to the end if it does not find the element
   // There is something called unordered_map
}
void ExplainMultiMap()
{
   multimap<int, char> mmp;
   mmp.insert({4, 'A'});
   mmp.insert({1, 'J'});
   mmp.insert({2, 'P'});
   mmp.insert({3, 'V'});
   mmp.insert({2, 'Q'}); // multiple entries for same key are allowed
   for (auto it : mmp)
   {
      cout << it.first << " --> " << it.second << endl;
   }
   auto it = mmp.equal_range(2);
   for (auto i = it.first; i != it.second; i++)
   {
      cout << (*i).first << "-->" << (*i).second << endl;
   }
}
void ExplainSort()
{

   //________SYNTAX_________
   /*
   #include <algorithm> // Required for sort()
sort(start_iterator, end_iterator);
*/

   int arr[5] = {5, 8, 6, 2, 3};
   sort(arr, arr + 5);
   for (int i = 0; i < 5; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   vector<int> nums = {5, 2, 9, 1, 7};

   sort(nums.begin(), nums.end()); // Ascending order

   for (int i : nums)
   {
      cout << i << " ";
   }
   // SORT IN DESCENDING ORDER
   /*
   sort(nums.begin(), nums.end(), greater<int>());

   */
}

void ExplainAccumulate()
{
   /*
   The accumulate() function is defined in the <numeric> header.
It is used to find the sum (or general accumulation) of elements in a
range (like an array or vector).*/
   //----------SYNTAX--------
   /*
   #include <numeric> // Required for accumulate()

   accumulate(start_iterator, end_iterator, initial_value);
   */

   // Time Complexity	O(n)
   int arr[5] = {5, 8, 6, 2, 3};
   cout << accumulate(arr, arr + 5, 0);
}
void ExplainCount()
{
   /*
   The count() function in C++ is used to count the number of occurrences of a specific value in a range (like an array or vector).

*/
   //_________-SYNTAX_________
   /*count(start_iterator, end_iterator, value);
    */
   int arr[5] = {5, 8, 6, 2, 3};

   int num = 5;
   cout << count(arr, arr + 5, num);
}
void ExplainFind()
{
   /*
   The find() function in C++ is used to search for a specific element in a range (like arrays, vectors, etc.). It returns an iterator to the first occurrence of the element, or the end() iterator if not found.*/
   //_________SYNTAX________
   /*
   find(start_iterator, end_iterator, value);
*/
   vector<int> v = {10, 20, 30, 40, 50};

   auto it = find(v.begin(), v.end(), 30);

   if (it != v.end())
   {
      cout << "Element found at position: " << it - v.begin() << endl;
   }
   else
   {
      cout << "Element not found" << endl;
   }

   int arr[] = {3, 5, 7, 9};
   auto itr = find(arr, arr + 4, 7);
}
void ExplainNextPermutation()
{
   string strk = "ABC";
   do
   {
      cout << strk << endl;
   } while (next_permutation(strk.begin(), strk.end()));
   // it has lot of things
}
void ExplainMaxElement()
{
   int arr[] = {10, 50, 30, 20, 40};
   int n = sizeof(arr) / sizeof(arr[0]);

   auto it = max_element(arr, arr + n);
   cout << "Max element is: " << *it << endl;
   // Similarly we can do for min element
}
void ExplainReverse()
{
   //---------SYNTAX--------
   /*
   #include <algorithm>

reverse(start_iterator, end_iterator);
*/
   int arr[] = {1, 2, 3, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);

   reverse(arr, arr + n); // Reverses the array

   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   vector<int> v = {10, 20, 30, 40};

   reverse(v.begin(), v.end());

   for (int i : v)
   {
      cout << i << " ";
   }
}
bool compare(int a, int b)
{
   return a > b; // Sort in descending order
}
void ExplainComparator()
{
   /*
   A comparator in C++ is a function or a functor (function object) that defines custom sorting logic when using sort() or other STL algorithms. It's used to override default sorting behavior.*/
   //-----------SYNTAX----------
   /*
   bool comparator(int a, int b)
   {
    return a > b;  // descending order
    }

sort(vec.begin(), vec.end(), comparator);

   */
   cout << endl;
   vector<int> v = {3, 1, 4, 1, 5, 9};
   sort(v.begin(), v.end(), compare);
   for (int x : v)
   {
      cout << x << " ";
   }
}
int main()
{
   ExplainPair();
   ExplainVector();
   ExplainList();
   ExplainStack();
   ExplainQueue();
   ExplainPQ();
   ExplainSet();
   ExplainMultiSet();
   ExplainMap();
   ExplainMultiMap();
   ExplainSort();
   ExplainAccumulate();
   ExplainCount();
   ExplainFind();
   ExplainNextPermutation();
   ExplainMaxElement();
   ExplainReverse();
   ExplainComparator();
   return 0;
}
