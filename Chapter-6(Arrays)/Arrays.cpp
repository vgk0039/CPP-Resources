#include <iostream>
int main()
{
   // Declaring an array
   int points[3];// array storing t*hree integers
   // reading the values
   std::cout << "Reading the points manually" << std::endl;
   std::cout << "point[0]" << points[0] << std::endl;
   std::cout << "point[1]" << points[1] << std::endl;
   std::cout << "point[2]" << points[2] << std::endl;
   // so on
   // if we dont put any value in an index it will have garbage value
   // Reading past bounds  of your array is bad
   //----------reading data using loop-----------
   for (size_t i{0}; i < 3; i++)
   {
      std::cout << "point[" << i << "]" << points[i] << std::endl;
   }
   // writing the data in an array
   //Doing this comment because i was bored  or I was just practising typiing. Pardon me for any miss spells in this comment.
   points[0] = 18;
   points[1] = 19;
   points[2] = 20;
   std::cout << "point[0]" << points[0] << std::endl;
   std::cout << "point[1]" << points[1] << std::endl;
   std::cout << "point[2]" << points[2] << std::endl;
   // writing out of bound points[15]=300;  is bad
   //------writing data in array using loops--------------
   for (size_t i = 0; i < 3; i++)
   {
      points[i] = i + 3;
   }
   // Declaring and initialising a]t the same time
   int balls[5]{1, 2, 3, 4, 5};
   // if we dont initialise all the elements those we leave out are initialised to 0
   // We can omit the size of the array at declaration
   int aus[]{1, 2, 3, 4, 5, 6};
   for (auto value : aus)
   {
      std::cout << "Aus : " << aus << std::endl;
   }
   // Constant arrays cant be modified
   const int IND[]{12, 15, 15};
   // IND[1]=20; -->cant change elements of a constant array
   // sum of an aaray
   int sum{0};
   for (auto value : aus)
   {
      sum += value;
   }
   std::cout << "Sum of the felements of the array is" << sum << std::endl;
   //---------size of an array at run time------------
   int wickets[]{3, 43, 45, 56, 18, 7};
   std::cout << "wickets size is : " << std::size(wickets) << std::endl;
   // or
   std::cout << "Size of wicket is " << (sizeof(wickets)) / (sizeof(wickets[0])) << std::endl;
   //------------Arrrays of characters--------
   char message[6]{'g', 'a', 'n', 'e', 's', 'h'}; // it is a c string if array size is not mentioned then it is not a c string

   std::cout << "Message : ";
   for (auto c : message)
   {
      std::cout << c;
   }
   // modifying elements of the array
   message[1] = 'b';
   for (auto c : message)
   {
      std::cout << c;
   }
   // directly printing charactar array
   std::cout << message << std::endl;
   // xcan also define a literal c string
   char message1[]{"Ganesh"}; // An implicit '\0' character is appended to the end of the string, making it a C string
   char message2[]{"Ganesh Karthik"};
   std::cout << message2 << std::endl;
   // cant direclty print arrays othr than character arrays

   return 0;
}

/*
--------ARRAYS-------------
Arrays in C++ are a collection of elements, all of the same type, stored in contiguous memory locations. They allow you to store and manipulate a fixed number of items under a single name.
-----Declaration Syntax------
data_type array_name[size];
Initialization: You can initialize arrays at the time of declaration:
int arr[5] = {1, 2, 3, 4, 5};
--->If you leave out the size, it is inferred from the number of elements provided:
--->Partial initialization sets the unspecified elements to zero:
--->Array elements are accessed using indices, starting at 0
--->character arrays have null terminator i.e. "\0"
--->If a character array is null terminated it is called as C-string
--->Read beyond bounds will read garbage or crash your program


*/