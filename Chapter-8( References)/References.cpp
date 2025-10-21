
// References are a way to set up aliases for our variables
//----DECLARE AND USE REFERENCES-----

#include <iostream>

int main()
{

   int int_data{33};
   double double_data{55};

   // References
   int &ref_int_data{int_data};
   double &ref_double_data{double_data};

   // Print stuff out
   std::cout << "int_data : " << int_data << std::endl;
   std::cout << "&int_data : " << &int_data << std::endl;
   std::cout << "double_data : " << double_data << std::endl;
   std::cout << "&double_data : " << &double_data << std::endl;

   std::cout << "=======================" << std::endl;

   std::cout << "ref_int_data : " << ref_int_data << std::endl;
   std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
   std::cout << "ref_double_data : " << ref_double_data << std::endl;
   std::cout << "&ref_double_data : " << &ref_double_data << std::endl;

   int_data = 111;
   double_data = 67.2;

   // Print stuff out
   std::cout << std::endl;
   std::cout << "int_data : " << int_data << std::endl;
   std::cout << "&int_data : " << &int_data << std::endl;
   std::cout << "double_data : " << double_data << std::endl;
   std::cout << "&double_data : " << &double_data << std::endl;

   std::cout << "=======================" << std::endl;

   std::cout << "ref_int_data : " << ref_int_data << std::endl;
   std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
   std::cout << "ref_double_data : " << ref_double_data << std::endl;
   std::cout << "&ref_double_data : " << &ref_double_data << std::endl;

   ref_int_data = 1012;
   ref_double_data = 1000.45;

   // Print stuff out
   std::cout << std::endl;
   std::cout << "int_data : " << int_data << std::endl;
   std::cout << "&int_data : " << &int_data << std::endl;
   std::cout << "double_data : " << double_data << std::endl;
   std::cout << "&double_data : " << &double_data << std::endl;

   std::cout << "=======================" << std::endl;

   std::cout << "ref_int_data : " << ref_int_data << std::endl;
   std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
   std::cout << "ref_double_data : " << ref_double_data << std::endl;
   std::cout << "&ref_double_data : " << &ref_double_data << std::endl;
   // Comparing references to pointers

   double double_value{12.34};
   double &ref_double_value{double_value}; // Reference to double_value
   double *p_double_value{&double_value};  // Pointer to double_value
                                           // Make the reference reference something else.
   double some_other_double{78.45};
   ref_double_value = some_other_double;
   //---------REFERENCES AND CONSTANTS-------
   //Non const reference
	std::cout << std::endl;
	std::cout << "Non const reference : " << std::endl;
	int age {27};
	const int& ref_age{age};
	/*
	std::cout << "age : " << age << std::endl;
	std::cout << "ref_age : " << ref_age << std::endl;
	
	
	//Can modify original variable through reference

	std::cout << std::endl;
	std::cout << "Modify original variable through reference : " << std::endl;
	
	ref_age++; //Mofify through reference
	
	std::cout << "age : " << age << std::endl;
	std::cout << "ref_age : " << ref_age << std::endl;
    */

   //Simulating reference behavior with pointers
   //const int * const p_age {&age};
   //*p_age = 45;
   return 0;
}

/*
--------REFERENCES--------
--->Do not use dereferencing for reading and writing
--->Can not be changed to reference some thing else
--->Must be initialised at declaration
---------POINTERS------
--->Must go through dereference operator to read / write through pointed to value
--->Can be changed to point somewhere else
--->Can be declared un initialised (Will  contain garbage addresses)


--->Cant make a reference refer to something else.References are somewhat like const pointers but they have a much friendlier syntax as they dont require dereferencing to read and write through reference data



*/