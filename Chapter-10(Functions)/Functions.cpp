#include <iostream>
// Function that takes a single parameter, and doesn't
// give back the result explicitly
void enter_bar(size_t age)
{ // Functions parameters
   if (age > 18)
   {
      std::cout << "You're " << age << " years old. Please proceed." << std::endl;
   }
   else
   {
      std::cout << "Sorry, you're too young for this. No offense! " << std::endl;
   }
   return;
}

// Function that takes multiple parameters and returns the result of the computation

// Function that doesnt' take parameters and returns nothing
void say_hello()
{
   std::cout << "Hello there" << std::endl;
   return; // You could omit this return statement for functions returning void
}

// Function that takes no parameters and return something
int lucky_number()
{
   return 99;
}

// Parameters passed this way are scoped localy in the function.
// Changes to them are not visible outside the function. What we
// have inside the function are actually COPIES of the arguments
// passed to the function.
double increment_multiply(double a, double b)
{

   std::cout << "Inside function , before increment : " << std::endl;
   std::cout << "a : " << a << std::endl;
   std::cout << "b : " << b << std::endl;

   double result = ((++a) * (++b));

   std::cout << "Inside function , after increment : " << std::endl;
   std::cout << "a : " << a << std::endl;
   std::cout << "b : " << b << std::endl;

   // Returning the result
   return result;
}
int max(int a, int b); // Function declaration , prototype
                       // Signature doesn't include return type
int min(int a, int b);

int inc_mult(int a, int b);
void say_age(int age)
{ // Parameter
   ++age;
   std::cout << "Hello , you are " << age << " years old! &age : " << &age << std::endl;
}
void say_age1(const int *age1); // Declaration

void modifyValue(int &x)
{
   x = 10; // Modifies the original value of x
}
int main()
{
   //-------One Definition Rule---------
   //--->Definitions cant show up more than once in entire program or translation unit
   //--------------First Hand On Functions----------
   //--->A function is a reusable piece of code that can take a number of optional inputs and produce some desirable output
   // Calling enter_bar
   /*
   //enter_bar(22); // Function arguments
   //enter_bar(15);

   for(size_t i{1} ; i < 20 ; ++i){
       enter_bar(i);
   }
   */

   // Calling max
   /*
   int x{22};
   int y{44};
   int result = max(100,20); // Arguments
   result = max(x,y);
   std::cout << "max : " << result << std::endl;
   */

   // Calling say_hello
   /*
   say_hello();
   */

   // Calling lucy_number
   /*
   int result{};
   result = lucky_number();
   std::cout << "result : " << result << std::endl;
   */

   double h{3.00};
   double i{4.00};

   std::cout << "Outside function , before increment : " << std::endl;
   std::cout << "h : " << h << std::endl;
   std::cout << "i : " << i << std::endl;

   double incr_mult_result = increment_multiply(h, i);

   std::cout << "Outside function , before increment : " << std::endl;
   std::cout << "h : " << h << std::endl;
   std::cout << "i : " << i << std::endl;

   //---------Function Declaration & Definition-----------

   //-->Some times it is more flexible to split the function into its header and vody and keep the code for each in different places
   // Declaration is also called prototype
   // The prototype needs to come before the function call in your file. Otherwise the compilation will fail.
   int x{5};
   int y{12};

   int result = min(x, y);
   std::cout << "min : " << result << std::endl;

   result = inc_mult(x, y);
   std::cout << "result : " << result << std::endl;
   //----------PASS BY VALUE--------------
   int age{23}; // Local
   std::cout << "age (before call) : " << age << "&age : " << &age << std::endl;
   say_age(age); // Argument
   std::cout << "age (after call) : " << age << "&age : " << &age << std::endl;
   //---------PASS BY POINTER ----------
   int age1{29};                                                                   // Local
   std::cout << "age (before call) : " << age1 << "&age : " << &age1 << std::endl; // 23
   say_age1(&age1);                                                                // Argument
   std::cout << "age (after call) : " << age1 << "&age : " << &age1 << std::endl;  // 24
   //----------PASS BY REFERENCE--------
   /*
    pass by reference means passing the actual reference (or address) of a variable to a function, rather than passing
    the value of the variable. This allows the function to modify the original value of the variable, rather than working on a copy.

   */
   int a = 5;
   std::cout << "Before: " << a << std::endl; // Output: 5
   modifyValue(a);
   std::cout << "After: " << a << std::endl; // Output: 10 (value of a is modified)

   return 0;
}
// Function definition. Shows up after main
int max(int a, int b)
{
   if (a > b)
      return a;
   else
      return b;
}

// Function definition. Shows up after main
int min(int a, int b)
{
   if (a < b)
      return a;
   else
      return b;
}

int inc_mult(int a, int b)
{
   return ((++a) * (++b));
}
void say_age1(const int *age1)
{ // Parameter
   ++(age1);
   std::cout << "Hello , you are " << *age1 << " years old! &age : " << &age1 << std::endl; // 24
}
/*
--->function signiture = function name + function parameter
--->----------SYNTAX---------
    return_type function_name(parameter_list)
    {
      // Function body
     }

--->----------Calling a function----
result_var = function_name(arg1,arg2);
---> Be carefull about implicit conversions

---> One definition rule : The same function implementation can't show up in the global namespace more than once
---> The linker searches for definitions in all transition units(.cpp) files in the project. Doesn't have to live in a .cpp file with the same name as header
---> header file i.e.(.h) contains declarations and .cpp files contains definitions

*/