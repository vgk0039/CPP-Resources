#include <iostream>
int main()
{
    //-------------for loop----------------
    int count{10};
    for (size_t i = 1; i <= count; ++i) // using size_t
    {
        std::cout << i << "\t" << "I love c++ " << std::endl;
    }
    // Using continue to skip an iteration
    for (int i = 1; i <= 5; i++)
    {
        if (i == 3)
            continue; // Skip the rest of the loop body when i equals 3
        std::cout << i << " ";
    }
    // Output: 1 2 4 5
    // Using break to exit early:
    for (int i = 1; i <= 10; i++)
    {
        if (i == 5)
            break; // Exit loop when i equals 5
        std::cout << i << " ";
    }
    // Output: 1 2 3 4

    //-------while loop----------
    int count1{1};

    // Print numbers from 1 to 5 using while loop
    while (count1 <= 5)
    {
        std::cout << "Count: " << count1 << std::endl;
        count1++; // Increment the counter
    }
    //---------do while loop----------
    do
    {
        std::cout << "Count: " << count1 << std::endl;
        count1++;
    } while (count1 <= 5);

    return 0;
}
/*-------FOR LOOP ----------
SYNTAX::
for (initialization; condition; increment/decrement)
{
    // code to be executed
}
--->Initialization: Executed once at the beginning of the loop.
--->Condition: Checked before each iteration. If true, the loop body executes; if false, the loop terminates.
--->Increment/Decrement: Updates the loop variable after each iteration

*/
/*----------sizez_t i---------------
C++, size_t is an unsigned integer type defined in the <cstddef> or <stddef.h> header. It is used to represent
sizes and counts in a way that is guaranteed to be large enough to index any array or represent the size of any
 object in memory

Key Points about size_t:
--->Unsigned Type: size_t cannot store negative values. This makes it ideal for sizes and indices.
--->Platform-Dependent: The actual size of size_t depends on the platform:
--->On a 32-bit system, size_t is usually 4 bytes (32 bits).
--->On a 64-bit system, size_t is usually 8 bytes (64 bits).
--->Defined in Standard Headers: It is part of the standard library and can be included using <cstddef> or <stddef.h>.
 why to use it::
 1.Avoids Signed/Unsigned Mismatch
 2.Portability
 .*/
/*-----------while loop------------
while (condition) {
   // Code to be executed repeatedly
}
when to use:
1.Use while when you don’t know the number of iterations in advance.
2.Use for when the number of iterations is known before entering the loop.


*/
/*---------do while loop---------------
SYNTAX:
do {
    // Code to execute
} while (condition);

When to Use do-while:
--->When you need the loop body to execute at least once before checking the condition.
--->For user-driven actions, like menus or input validation.
--->Guaranteed Execution: The loop body executes at least once, even if the condition is false initially.
--->Condition Checked at the End: This is useful when the loop body needs to run before the condition is evaluated.
--->Infinite Loop: If the condition is always true, the loop will run indefinitely.


*/