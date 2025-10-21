#include<iostream>
int main()
{
int num1=15;//decimal
int num2=036;//octal
int num3=0x000a3;//hexadecimal
int num4=0b001001;//binary
std::cout<<num1<<"\n"<<num2<<"\n"<<num3<<"\n"<<num4<<std::endl;
//----------Intigers
//Variable may contain random garbage value
int seed;
int seedscount{};//intializes to Zero
int seeds_count{10};//initialize to 10
int seeds{seedscount+seeds_count};//Can use expressions as initializer
//We can use paranthesis instead of{} during initialization
//syntax for initialization   : typename variable_name {};
std::cout<<sizeof(int)<<std::endl;//size of tells the size of the datatype
    //--------Intiger modifiers
    /*
    ex:short,long signed,unsigned,all p&c of these
    ----->These modifiers only apply to integral types:
           those in which you can store decimal numbers

    */
//----------------FRACTIONAL NUMBERS(Floating types)
float num11{1.12345677889445};
std::cout<<num11<<std::endl;
//--->Remember the suffixes when initializing floating point variables
//      otherwise the default will be double
//--->Double works well in many situations so we will see it used a lot


//-----------BOOLEANS
bool red{true};
bool green{false};

if (red==true)
{
    std::cout<<"Stop !"<<std::endl;
}
else{
std::cout<<"Go through"<<std::endl;
}
std::cout<<"Is :"<<red<<std::endl;
//------Characters and Texts--------
char naam {'v'};
std::cout<<naam<<std::endl;
char val{65};
std::cout<<static_cast<int>(val)<<std::endl;//prints number itself
std::cout<<val<<std::endl;//prints ascii value
//------auto -Key word
//it lets the compiler to deduce the type for us
auto variable{5};
auto variable1{12.5};
auto variable2{'g'};
std::cout<<sizeof(variable)<<std::endl;//4
std::cout<<sizeof(variable1)<<std::endl;//8
std::cout<<sizeof(variable2)<<std::endl;//1  

    return 0;
}
/*
Variable:A named piece of memory that you use to store
         specific types of data
---->Functional variable initialization is using paranthesis in place of braces{}
      @it is less safe does implicit conversion
      @chops of decimal value.Silent killer
----> int height{181.3}  here we get error during compilatio if we use () instead of {}
    we wont know that it got truncated

---->It is possible to assign a valid ASCII code to a char variable,
and the corresponding character will be stored in.We can choose
that either as a character or a regular integrak value.
*/