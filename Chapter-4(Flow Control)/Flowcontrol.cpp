// CONDITIONAL PROGRAMMING
#include <iostream>
int main()
{
    //-------if----------
    int number = 10;

    if (number > 5)
    {
        std::cout << "Number is greater than 5." << std::endl;
    }
    //---------if-else--------
    int number1 = 3;

    if (number1 > 5)
    {
        std::cout << "Number is greater than 5." << std::endl;
    }
    else
    {
        std::cout << "Number is not greater than 5." << std::endl;
    }
    //-----else if ladder---------
    int number2 = 0;

    if (number2 > 0)
    {
        std::cout << "Number is positive." << std::endl;
    }
    else if (number2 < 0)
    {
        std::cout << "Number is negative." << std::endl;
    }
    else
    {
        std::cout << "Number is zero." << std::endl;
    }
    // switch case
    int day = 3;

    switch (day)
    {
    case 1:
        std::cout << "Monday" << std::endl;
        break;
    case 2:
        std::cout << "Tuesday" << std::endl;
        break;
    case 3:
        std::cout << "Wednesday" << std::endl;
        break;
    default:
        std::cout << "Invalid day" << std::endl;
        break;
    }
    //---------Ternary operator---------
    int a = 10, b = 20;

    int max = (a > b) ? a : b; // If a > b, max is a; otherwise, max is b.

    std::cout << "The maximum value is: " << max << std::endl;

    return 0;
}
/* ---------if------
SYNTAX::--->
if (condition)
{
    // Code to execute if the condition is true
}

*/
/*----------if else----------
SYNTAX::--->
if (condition) {
    // Code to execute if the condition is true
} else {
    // Code to execute if the condition is false
}

*/
/*----else if ladder------
SYNTAX::--->
if (condition1) {
    // Code to execute if condition1 is true
} else if (condition2) {
    // Code to execute if condition2 is true
} else {
    // Code to execute if none of the conditions are true
}
*/
/*
---> The condition in if must evaluate to a boolean (true or false).
--->Curly braces {} are optional if the block has only one statement, but using them is
     a good practice for readability.
--->Nested if statements are allowed but can become complex; consider using functions or
    logical operators for clarity.
*/
/*----------switch statement------------
SYNTAX::--->
switch (expression) {
    case constant1:
        // Code to execute if expression == constant1
        break;  // Exit the switch statement
    case constant2:
        // Code to execute if expression == constant2
        break;
    // Additional cases as needed
    default:
        // Code to execute if no case matches
        break;
}

How It Works:
1.The expression is evaluated once.
2.The result is compared against the values in each case.
3.If a match is found, the corresponding block of code is executed.
4.The break statement exits the switch to prevent executing subsequent cases.
5.If no cases match, the default block (optional) is executed.


Points:
1.The switch expression must be of an integer or enumerated type (e.g., int, char, etc.).
2.The case values must be constants or literals, not variables or expressions.
3.Use break to avoid fall-through, unless intentionally desired.
4.The default case is optional but recommended for robustness.
--->The bbreak statemennt after each case is very important.It stops
processing the switch block when a succesfull case has been
found.If the breeak statement is not there all the case following
the current case will be executed .
*/
/*---------TERNARY OPERATOR-----------
SYNTAX:
condition ? expression1 : expression2;
--->condition: A boolean expression that is evaluated.
--->expression1: Returned if the condition is true.
--->expression2: Returned if the condition is false.

*/