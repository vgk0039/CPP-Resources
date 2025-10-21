#include <iostream>
int main()
{
    std::string name;
    std::cout<<"Ram Ram Bhai"<<std::endl;
    /*In C++, endl is a manipulator used with the std::ostream class (like std::cout) to do two things:
    1.Insert a newline character (\n) into the output stream, moving the cursor to the beginning of the next line.
    2.Flush the output buffer, ensuring all output up to that point is sent immediately to the console or output device.*/
    std::getline(std::cin,name);//getline helps us to input data with the spaces
    std::cout<<name;
    std::cout<<"Saareyane"<<std::endl;
    return 0;
}
/*----------------------------------
In C++, compile-time errors, runtime errors, and warnings have distinct meanings 
and occur at different stages of program execution. Here's an explanation with examples:

1. Compile-Time Errors
Occur during the compilation phase.
Prevent the program from being successfully compiled.
Examples include syntax errors, missing headers, and type mismatch issues.
Causes:

Syntax errors (e.g., missing semicolon, unmatched brackets).
Using undeclared variables.
Type mismatches.
Example:

#include <iostream>
int main() {
    std::cout << "Hello World" // Missing semicolon causes a compile-time error.
    return 0;
}
----------------------------------------
2. Runtime Errors
Occur while the program is running.
These errors are due to invalid operations or logical issues that are not detectable during compilation.
Cause the program to crash or behave unexpectedly.
Causes:

Division by zero.
Null pointer dereferencing.
Accessing out-of-bounds memory in arrays.
Infinite loops or recursion.
Example:
#include <iostream>
int main() {
    int a = 10, b = 0;
    std::cout << a / b; // Division by zero causes a runtime error.
    return 0;
}
-----------------------------------------
3. Warnings
Indicate potential issues in the code but do not stop compilation.
Can lead to bugs or undefined behavior if ignored.
Modern compilers like GCC and Clang provide detailed warnings.
Common Warnings:

Unused variables.
Implicit type conversion that may lose data.
Using uninitialized variables.
Example:
#include <iostream>
int main() {
    int x; // Uninitialized variable.
    std::cout << x; // Compiler issues a warning but the code compiles.
    return 0;
}
Warning Output (GCC/Clang):
warning: ‘x’ is used uninitialized in this function [-Wuninitialized]

-----------------------------------------------------
Differences
Aspect	        Compile-Time Errors	    Runtime Errors	                          Warnings
When It Occurs	During compilation	    While the program is running	          During compilation
Effect	       Prevents compilation	    Causes program crash or unexpected behavior	  Program compiles but with a warning
Examples	  Syntax errors, missing declarations	Division by zero, null pointer access	Unused variables, type mismatch
-----------------------------
How to Handle
Compile-Time Errors:

Fix syntax issues as shown by the compiler.
Ensure all variables, headers, and functions are correctly declared.

Runtime Errors:
Use exception handling (try-catch).
Test your program with various inputs.
Use debugging tools or print statements to trace issues.

Warnings:
Address them immediately.
Use compiler flags like -Wall (GCC/Clang) to enable all warnings.
Resolve issues to prevent unexpected behavior.
Let me know if you'd like help fixing specific errors or warnings! 😊
*/
//----------------------------------------
