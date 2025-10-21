#include <iostream>
#include <string>

void max_str(const std::string &input1, const std::string input2,
             std::string &output)
{
   if (input1 > input2)
   {
      output = input1;
   }
   else
   {
      output = input2;
   }
}

void max_int(int input1, int input2, int &output)
{
   if (input1 > input2)
   {
      output = input1;
   }
   else
   {
      output = input2;
   }
}

void max_double(double input1, double input2, double *output)
{
   if (input1 > input2)
   {
      *output = input1;
   }
   else
   {
      *output = input2;
   }
}

// Definition
auto max(int &a, int &b)
{
   if (a > b)
   {
      return a;
   }
   else
   {
      return b; // Will return a copy.
   }
}

int find_character_v0(const std::string &str, char c)
{
   // If found , return the index, else return -1
   int not_found{-1};
   for (size_t i{}; i < str.size(); ++i)
   {
      if (str.c_str()[i] == c)
      {
         return i;
      }
   }
   return not_found;
}

void find_character_v1(const std::string &str, char c, bool &success)
{
   // If found set success to true, else set to false
   for (size_t i{}; i < str.size(); ++i)
   {
      if (str.c_str()[i] == c)
      {
         success = true;
         return;
      }
   }
   success = false;
}
int sum(int a, int b)
{
   int result = a + b;
   std::cout << "In : &result(int) :  " << &result << std::endl;
   return result;
}

std::string add_strings(std::string str1, std::string str2)
{
   std::string result = str1 + str2;
   std::cout << "In : &result(std::string) :  " << &result << std::endl;
   return result;
}
int &max_return_reference(int &a, int &b)
{
   if (a > b)
   {
      return a;
   }
   else
   {
      return b;
   }
}

int &sum(int &a, int &b)
{
   int result = a + b;
   return result; // Reference to local variable returned
}

// int &max_input_by_value(int a, int b)
// {
//    if (a > b)
//    {
//       return a; // Reference to local variable returned
//    }
//    else
//    {
//       return b; // Reference to local variable returned
//    }
// }

int main()
{

   int x{5};
   int y{9};

   int int_val = max(x, y);

   std::string str1{"Hello World in C++20!"};
   char c{'r'};

   /*
   int index =  find_character_v0(str1,c);

   if((find_character_v0(str1,c))!=-1){
       std::cout << "Found character " << c << " at index : " << index << std::endl;
   }else{
      std::cout << "Didn't find our character" << std::endl;
   }
   */

   /*
 std::string out_str;
 std::string string1("Cassablanca");
 std::string string2("Bellevue");

 max_str(string1,string2,out_str);
 std::cout << "max_str : " << out_str << std::endl;
  */

   /*
    int out_int;
    int in1{45};
    int in2{723};
    max_int(in1,in2,out_int);
    std::cout << "max_int : " << out_int << std::endl;
    */

   bool success{false};

   find_character_v1(str1, c, success);

   if (success)
   {
      std::cout << "Found character " << c << " in our string " << std::endl;
   }
   else
   {
      std::cout << "Didn't find our character" << std::endl;
   }
   double out_double;
   double in_double1{45.8};
   double in_double2{76.9};
   max_double(in_double1, in_double2, &out_double);
   std::cout << "max_double : " << out_double << std::endl;

   /*
   int x{15};
   int y{9};
   int result = sum(x,y);
   std::cout << "Out : &result(int) :  " << &result << std::endl;
   std::cout << "result : " << result << std::endl;
   */

   std::string in_str1{"Hello"};
   std::string in_str2{" World!"};
   std::string result_str = add_strings(in_str1, in_str2);
   std::cout << "Out : &result_str(std::string) :  " << &result_str << std::endl;
   std::cout << "result_str : " << result_str << std::endl;
   /*
     int x{14};
     int y{9};
     int& ref_max = max_return_reference(x,y); // Reference
     int val = max_return_reference(x,y); // Copy

     std::cout << "ref_max : " << ref_max << std::endl;
     std::cout << "val : " << val << std::endl;
     std::cout << "x : " << x << std::endl;
     std::cout << "y : " << y << std::endl;

     ref_max++;

     std::cout << "----- " << std::endl;
     std::cout << "ref_max : " << ref_max << std::endl; // 15
     std::cout << "val : " << val << std::endl; // 14
     std::cout << "x : " << x << std::endl; // 15
     std::cout << "y : " << y << std::endl; // 9

   */

   /*
    int x{14};
    int y{9};
    int& result = sum(x,y); // Reference
    std::cout << "result : " << result << std::endl;
   */

   // int x{14};
   // int y{9};
   //  int &result = max_input_by_value(x, y); // Reference
   //  std::cout << "result : " << result << std::endl;

   std::cout << "Done!" << std::endl;
   return 0;
}

/*
---> Output parameters should be passed in such a way that you can modify the arguments
from inside the function.Options are passing by reference or by pointer. References are preffered in c++.
---> Input parameters shouldn't be modifiable from inside a function. The function really need to get input (read) from the arguments. You enforce modification restrictions with the const keyword
Options are passing by const reference,passing by pointer to const or even passing by const pointer to const.









*/