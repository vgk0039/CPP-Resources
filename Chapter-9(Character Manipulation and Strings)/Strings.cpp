#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
int main()
{
   //------Introduction & Character manipulation-------
   // We will basically know Better facilities to handle text data in our c++ programs
   //*** cppreference.com****** Visit this website for many crazy things
   // Checking a character is a alphanumeric
   std::cout << "C is alphanumeric : " << std::isalnum('C') << std::endl; // We can use it as a test condition
   //-------C string Manipulation------
   const char message1[]{"The sky is blue"};
   std::cout << "strlen(message1):" << std::strlen(message1) << std::endl;
   // std::strlen : Find the length of a string
   //  real arrays and those decayed into pointers

   // Array decays into pointer when we use const char*
   const char *message2{"The sky is blue."};
   std::cout << "message1 : " << message1 << std::endl;

   // strlen ignores null character
   std::cout << "strlen(message1) : " << std::strlen(message1) << std::endl;
   // strlen still works with decayed arrays
   std::cout << "strlen(message2) : " << std::strlen(message2) << std::endl;

   // Prints size of pointer
   std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl;
   // std::strcmp - signature : int strcmp( const char *lhs, const char *rhs );
   // Returns negative value if lhs appears before rhs in lexicographical order,
   // Zero if lhs and rhs compare equal.
   // and Positive value if lhs appears after rhs in lexicographical order.

   std::cout << std::endl;
   std::cout << "std::strcmp : " << std::endl;
   const char *string_data1{"Alabama"};
   const char *string_data2{"Blabama"};

   char string_data3[]{"Alabama"};
   char string_data4[]{"Blabama"};

   // Print out the comparison
   std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
             << std::strcmp(string_data1, string_data2) << std::endl;

   std::cout << "std::strcmp (" << string_data3 << "," << string_data4 << ") : "
             << std::strcmp(string_data3, string_data4) << std::endl;

   string_data1 = "Alabama";
   string_data2 = "Alabamb";

   // string_data3 = "Alabama";
   // string_data4 = "Alabamb";

   // Print out the comparison
   std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
             << std::strcmp(string_data1, string_data2) << std::endl;

   string_data1 = "Alacama";
   string_data2 = "Alabama";

   // Print out the comparison
   std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
             << std::strcmp(string_data1, string_data2) << std::endl;

   string_data1 = "India";
   string_data2 = "France";

   // Print out the comparison
   std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
             << std::strcmp(string_data1, string_data2) << std::endl;

   string_data1 = "Kigali";
   string_data2 = "Kigali";

   // Print out the comparison
   std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
             << std::strcmp(string_data1, string_data2) << std::endl;

   // std::strncmp : int strncmp( const char *lhs, const char *rhs, std::size_t count );
   // Compares n characters in the strings
   // Returns : Negative value if lhs appears before rhs in lexicographical order.
   // Zero if lhs and rhs compare equal, or if count is zero.
   // Positive value if lhs appears after rhs in lexicographical order.

   // Print out the comparison

   const char *string_data11{"Alabama"};
   const char *string_data22{"Blabama"};
   size_t n{3};
   std::cout << std::endl;
   std::cout << "std::strncmp : " << std::endl;
   std::cout << "std::strncmp (" << string_data11 << "," << string_data22 << "," << n << ") : "
             << std::strncmp(string_data11, string_data22, n) << std::endl;

   string_data11 = "aaaia";
   string_data22 = "aaance";

   std::cout << "std::strncmp (" << string_data11 << "," << string_data22 << "," << n << ") : "
             << std::strncmp(string_data11, string_data22, n) << std::endl;

   n = 5;

   std::cout << "std::strncmp (" << string_data11 << "," << string_data22 << "," << n << ") : "
             << std::strncmp(string_data11, string_data22, n) << std::endl;

   string_data11 = "aaaoa";
   string_data22 = "aaance";

   std::cout << "std::strncmp (" << string_data11 << "," << string_data22 << "," << n << ") : "
             << std::strncmp(string_data11, string_data22, n) << std::endl;

   // Find the first occurrence of a character
   // CODE STOLEN FROM THE DOCS :

   std::cout << std::endl;
   std::cout << "std::strchr : " << std::endl;
   // doc : https://en.cppreference.com/w/cpp/string/byte/strchr

   // we use std::strchr to find all the characters one by one.

   const char *const str{"Try not. Do, or do not. There is no try."};
   // Can make this a const pointer to prevent users from making it point somewhere else
   char target = 'T';
   const char *result = str;
   size_t iterations{};

   while ((result = std::strchr(result, target)) != nullptr)
   {
      std::cout << "Found '" << target
                << "' starting at '" << result << "'\n";

      // Increment result, otherwise we'll find target at the same location
      ++result;
      ++iterations;
   }
   std::cout << "iterations : " << iterations << std::endl;

   // A lesser version that will loop 25 times

   // Find the first occurrence of a character
   // CODE STOLEN FROM THE DOCS :
   std::cout << std::endl;
   std::cout << "std::strchr : " << std::endl;
   // doc : https://en.cppreference.com/w/cpp/string/byte/strchr

   // we use std::strchr to find all the characters one by one.

   // doc : https://en.cpprefere
   //-----------String concatination-------
   std::cout << std::endl;
   std::cout << "std::strcat : " << std::endl;
   // doc : https://en.cppreference.com/w/cpp/string/byte/strcat

   char dest[50] = "Hello ";
   char src[50] = "World!";
   std::strcat(dest, src);                      // Some compilers (MSVC) think these functions are unsafe!
   std::cout << "dest : " << dest << std::endl; // Hello World
   std::strcat(dest, " Goodbye World!");
   std::cout << "dest : " << dest << std::endl; // Hello World Goodbye World!
   std::cout << std::endl;
   std::cout << "More std::strcat : " << std::endl;

   char *dest1 = new char[30]{'F', 'i', 'r', 'e', 'l', 'o', 'r', 'd', '\0'};
   char *source1 =
       new char[30]{',', 'T', 'h', 'e', ' ', 'P', 'h', 'e', 'n', 'i', 'x', ' ', 'K', 'i', 'n', 'g', '!', '\0'};

   // NOTE TO SELF :
   // Describe what's going to happen in std::strcat before you do the cat :
   // source is going to be appended to dest, and the process
   // will start by overriding the null character in dest

   std::cout << "std::strlen(dest1) :" << std::strlen(dest1) << std::endl;
   std::cout << "std::strlen(source1) : " << std::strlen(source1) << std::endl;

   std::cout << "Concatenating..." << std::endl;
   std::strcat(dest1, source1);

   std::cout << "std::strlen(dest1) :" << std::strlen(dest1) << std::endl;
   std::cout << "dest1 : " << dest1 << std::endl;
   // std::strncpy : Copy n characters from src to dest -
   // signature : char *strncpy( char *dest, const char *src, std::size_t count );
   std::cout << std::endl;
   std::cout << "std::strncpy:" << std::endl;
   const char *source4 = "Hello";
   char dest4[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'}; // Have to put the terminating
                                                        // null char if we want to print

   std::cout << "dest4 : " << dest4 << std::endl;

   std::cout << "Copying..." << std::endl;
   std::strncpy(dest4, source4, 5);

   std::cout << "dest4 : " << dest4 << std::endl;
   std::string str1{"Hello there"};

   // Size of a string : doesn't count the null terminator
   std::cout << "str1.size() : " << str1.size() << std::endl;

   // Reading characters in std::string : array index operator
   // Regular indexed loop. Can also be adapted to use while and do-while
   // This is left as an exercise.
   std::cout << std::endl;
   std::cout << "For loop with array index notation : " << std::endl;

   std::cout << "str1(for loop) : ";
   for (size_t i{}; i < str1.size(); ++i)
   {
      std::cout << " " << str1[i];
   }
   std::cout << std::endl;
   std::string str11{"Hello there"};
   std::cout << std::endl;
   std::cout << "Using range based for loop : " << std::endl;

   std::cout << "str1(range based for loop) : ";
   for (char value : str11)
   {
      std::cout << " " << value;
   }
   std::cout << std::endl;

   // at() syntax to target characters

   std::cout << std::endl;
   std::cout << "Using the std::string::at() method : " << std::endl;

   std::string str15{"Hello there"};
   std::cout << "str1 : (for loop with at()) : ";

   for (size_t i{}; i < str1.size(); ++i)
   {
      std::cout << " " << str1.at(i);
   }
   std::cout << std::endl;
   std::string str14{"Hello there"};
   str1[0] = 'B';
   str1.at(1) = 'a';
   std::cout << "str1(modified) : " << str14 << std::endl;
   // Getting the front and back characters
   std::string str23{"The Phoenix King"};
   char &front_char = str23.front();
   char &back_char = str23.back();
   std::cout << "The front char in str2 is : " << front_char << std::endl;
   std::cout << "The back char in str2 is : " << back_char << std::endl;

   front_char = 'r';
   back_char = 'd';

   std::cout << "str2 : " << str23 << std::endl;
   std::string str2{"The Phoenix King"};
   const char *wrapped_c_string = str23.c_str();
   std::cout << "Wrapped c string : " << wrapped_c_string << std::endl;
   // wrapped_c_string[0] = 'e'; // Compiler error
   std::string str22{"Hello World"};

   char *data = str22.data();
   std::cout << "Wrapped c string : " << data << std::endl;

   data[0] = 'B'; // This also changes std::string.

   std::cout << "Wrapped c string (after modification) : " << data << std::endl;
   std::cout << "Original string (after modification ) :" << str2 << std::endl;
   return 0;
}
/*
--->C-Strings are not safe or convinient to work with in c++
--->Array decays into pointer when we use const char
--->Strlen ignores null characters
--->sizeof includes the null characters
--->strlen still work with decayed arrays
--->std::strcmp - signiture : int strcmp(const char *lhs,const char *rhs);
--->Returns the negative value if lhs appears before rhs in lexiological order,zero if lhs and rhs compare equal and positive value if lhs PPEARS AFTER RHS  in lexiological order
--->many crazy things in documentation









*/