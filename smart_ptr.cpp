/************************************************************************************************************
Practice 2: Smart Pointer
Design Description
Design a class named smart_ptr which works exactly like a primitive pointer. It should work like following 
*********************************************************************************************************/
#include <iostream>
using namespace std;

template<class T > 
struct smart_ptr 
{ 
   T *ptr;  // Actual pointer  
   // Constructor 
   smart_ptr(T *p ) { ptr = p; }  
   smart_ptr(const smart_ptr <T> &)=delete;
  
   // Destructor 
   ~smart_ptr() { delete(ptr); }   
  
   // Overloading dereferencing operator 
    T &operator *() { 
    return *ptr; } 
    T * operator -> () { 
    return ptr; }
};

int main()
{
    // 1. Should work with primitive data types
    smart_ptr<int> i_ptr(new int);

   // ref2 = var;

    *i_ptr = 5;

    cout << *i_ptr << endl;

    // 2. Should work with class & struct
    struct test
    {
        int var;
        test() { cout << "C\n"; }
        ~test() { cout << "D\n"; }
    };

    smart_ptr<test> t_ptr(new test);

    auto ptr2 = t_ptr;
    t_ptr->var = 10;

    cout << t_ptr->var << endl;
//
//    // 3. Copy construction
    auto ptr = i_ptr;

    cout << *ptr << endl;

    return 0;
}
/*********************************************************************************************
Note: You are not allowed to change the main function. Write your code within the design class.
Output
5
C
10
5
D
Concepts Targeted
Operator(`->` & `*`) overloading
Template
Copy constructor
Destructor
*************************************************************************************************/
