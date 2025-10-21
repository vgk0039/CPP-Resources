#include <iostream>
int main()
{
    std::cout << "Hello world      " << std::endl;
    //-----Declaring Pointers--------
    int *p_num{}; // can only store an address of a variable of type int
    // Explicitely initialize a null ptr
    int *p_number{nullptr};
    //-------Initialising pointer and assignining them data
    int int_var{43};
    int *p_int{&int_var}; //& is called address of operator
    // Dereferencing a pointer :
    int *p_int2{nullptr};
    int int_data{56};
    p_int2 = &int_data;
    std::cout << "Value : " << *p_int2 << std::endl;
    //--------Pointer to char----
    // Declaring pointer to char
    char *p_char_var{nullptr};
    char char_var{'A'};
    p_char_var = &char_var;
    // Initialse with string literals
    const char *p_message{"Hello "}; // Gonna be array of constant characters

    //----------Program Memory Map---------
    //--->Virtual Memory :: A trick that fools our program into thinking it is the only program running on our OS and all memory resourses belong to it.
    //--->Each program is abstracted into a process and each process has access to the memory range 0~2^n - 1. Where n is 32 on 32 bit OS and 64 on 64 bit Systems
    // --->The entire program is not loaded in real memory by the CPU and Memory management unit . Only parts that are about to be executed are loaded. Making effective use of real memory
    //--->The memory map is a standard format defined by the OS. All programs written for that OS must conform to it , It is usuallydivided into some sections
    //-----------Dynamic Memory Allocation---------
    // Initialise the pointer with dynamic memory .Dynamically allocate memory at run time and make a pointer point to it
    int *p_num4{nullptr};
    p_num4 = new int; /* Here dynamically allocate space for a single int on the heap.
     This memory will belongs to our program now.
     The system cant use it for anything else until we return it.
     After this line executes,we will have a valid memory locations allocated.
     The size of the allocated memory will be such that it can store the type pointed to by the pointer*/
    *p_num4 = 77;     // writing into dynamically allocated memory
    delete p_num4;
    p_num4 = nullptr;
    // it is possible to initialise the pointer with a valid address up on declaration. Not with a null ptr
    int *p_num5{new int};     // Memory location contains junk value
    int *p_num6{new int(22)}; // Use direct initialisation
    int *p_num7{new int{25}}; // Use uniform initialisation
    // Remember to release the memory
    delete p_num5;
    p_num5 = nullptr;
    // We can reuse pointers
    p_num5 = new int(69);
    std::cout << "p_num : " << *p_num5 << std::endl;
    //----------DNGLING POINTERS----------
    //--->A pointer that doesnt point to valid memory address.Trying to dereference and use a dangling pointer will result in undefined behavior.
    //---Uninitialised pointer
    int *number;
    // std::cout<<"number : "<<*number<<std::endl;//Crash
    //----------Deleted pointer
    delete number;
    // std::cout<<"number(After deletion) : "<<*number<<std::endl;//Crash
    //-----Multiple pointers pointing to same memory
    //---------MEMORY LEAK------
    //--->When we loose access to memory that is dynamically allocated
    //--------------******DYNAMIC ARRAYS******---------------
    //--->Arrays are allocated in the heap with the new operator.Can also use the std::nothrow version of new
    size_t size{10};
    // Different ways you can declare an array
    // Dynamically and how they are initialised
    double *p_salaries{new double[size]};                             // salaries array will contain garbage value
    int *p_students{new (std::nothrow) int[size]{}};                  // all values initialised to 0
    double *p_scores{new (std::nothrow) double[size]{1, 2, 3, 4, 5}}; // Allocating memory space for an array of size double vars. First 5 will be initialised with 1,2,3,4,5 and the rest will be 0's
    // nullptr check and use the allocated array
    if (p_scores)
    {
        // print out elements. Can use regular array access notation,or pointer arithmetic
        for (size_t i{}; i < size; ++i)
        {
            std::cout << "Value :" << p_scores[i] << ":" << *(p_scores + i) << std::endl;
        }
    }
    // Deleting Memory [Array Version]
    delete[] p_scores;
    p_scores = nullptr;
    return 0;
}
/*-------Pointers-------
--->Pointers in C++ are a powerful feature that allows you to directly access and manipulate memory.\
--->A pointer is a variable that stores the memory address of another variable.
     ##Pointers are used to work with memory more efficiently
     ##They are essential for dynamic memory allocation, passing large structures or classes to functions, and building complex data structures like linked lists and trees.
---> All pointer varibles have the same size in a given system
--->Pointer only store the type for which it was declared
--->We can also change the address stored in a pointer any time
--->We cannot cross assign between pointers of different types
--->We can use normal pointer to char like we have been using for
    double,int and anything else
--->Pointer to char can also do something special. We can initialise with a string literal :C-String
--->String literal is made up of const char .Trying to modify any of them will result in a disaster
--->Always initialise the pointers before you use them
--->Calling delete twice on a pointer is really bad!!
--------------------DANGLING POINTERS------------------
--->THREE TYPES:1.Uninitialised Pointer>>>solution::Initialise our pointer
                2.Deleted pointers>>>solution::Reset Pointer after deletion
                3.Multiple pointers pointing to same memory>>>Solution::Make sure the owner pointer is very clear
--------------When new fails-------------
--->In some rare cases the new operator will fail to allocate dynamic memory from the heap.When that happens and you have no mechanism in place to handle that failure an exception will be thrown and our program will crash.
 -----------NULL POINTER SAFETY--------------
 --->Make sure you are working with pointers containing valid memory addresses.
--->Calling delete on a nullptr is OK.This wont cause any problem if p_number contains nullptr
--->Pointers initialised with dynamic arrays are different from arrays :
--->std::size doesnt work on them and they dont support range based for loops
--->We say that the dynamically allocated array has decayed into a pointer


*/