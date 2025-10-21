#include <iostream>
#include <iomanip> //It provides tools to format the output of a program in a controlled and visually appealing way
#include <limits>  //numeric limits
#include <cmath>   //math functions

int main()
{
   // addition
   int num1{5};
   int num2{12};
   int sum{num1 + num2};
   std::cout << sum << std::endl;
   // Subtraction
   int sub{num1 - num2};
   std::cout << sub << std::endl;
   // Multiplication--->Gives quotient
   int mul{num1 * num2};
   std::cout << mul << std::endl;
   // division
   int div{num2 / num1};
   std::cout << div << std::endl;
   // Modulus--->Gives Remainder
   int mod{num2 % num1};
   std::cout << mod << std::endl;
   // we cannot use modulus operator on floating point number .It doesnt make any sense chutiye
   //---------Precedence and associativity---------
   // precedence and associativity determine the order in which operators are evaluated in expressions.
   //---------Prefix and postfix----
   int val{5};
   // increment by 1
   // val=val+1;
   // instead postfix
   std::cout << val++ << std::endl;
   std::cout << val << std::endl;
   //--------COMPOUND ASSIGNMENT OPERATOR-----

   int ball{5};

   std::cout << ball << std::endl;
   ball += 5;
   std::cout << ball << std::endl;
   //------RELATIONAL OPERATOR--------

   //------------LOGICAL OPERATORS-------
   bool a{true};
   bool b{false};
   std::cout << "a && b \n"
             << (a && b) << std::endl;
   std::cout << "a || b \n"
             << (a || b) << std::endl;
   std::cout << "This is a message for Ganesh(Padhle BKL)> Comeback maarna hai " << std::endl
             << std::flush;
   // MATH FUNCTIONS
   double weight{67.7};
   std::cout << "Weight rounded to floor is" << std::floor(weight) << std::endl;
   std::cout << "Weight rounded to ceil is" << std::ceil(weight) << std::endl;
   double exponential = std::exp(10);
   std::cout << "exponential is :" << exponential << std::endl;
   std::cout << "3^4 is " << std::pow(3, 4) << std::endl;

   return 0;
}
/*
PRECEDENCE
--->Determines the order in which operators are evaluated when there are multiple operators in an expression.
--->Operators with higher precedence are evaluated before those with lower precedence.
ASSOCIATIVITY
--->Determines the order of evaluation when operators have the same precedence
--->Can be left-to-right (left-associative) or right-to-left (right-associative).
--->Parentheses () can be used to override precedence

*/
/*
1. Prefix Operators (++x, --x)
Increment/Decrement happens first: The value of the variable is changed before it is used in the expression.
2. Postfix Operators (x++, x--)
Increment/Decrement happens later: The current value of the variable is used in the expression before it is changed.
--->There is nothing like X** or**X or X// or //X
*/
/* Relational operators
Relational operators in C++ are used to compare two values or expressions. The result of a relational operation
is a boolean value: true if the condition is met, and false otherwise.
*/
/*
LOGICAL OPERATORS
Logical operators in C++ are used to combine or modify boolean expressions and make logical decisions in control flow.
 The result of a logical operation is a boolean value: true or false.
*/
/*
OUT PUT FORMATTING
ex:std::endl,std::flush,std::setw()-->keeps things nicely,
std::setw() : Adjusts the field width for the item about to be printed
--->The setw() manipulator only affects the next value to be printed
*/
/*
NUMERIC LIMITS
*/
/*
MATH FUNCTIONS

*/
