#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a, char b)
{
    printf("Value of a is %d & %c\n", a,b);
}
  
int main()
{
    // fun_ptr is a pointer to function fun() 
    void (*fun_ptr)(int,char) = &fun;
  
    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
  
    // Invoking fun() using fun_ptr
    (*fun_ptr)(10,'4');
  
    return 0;
}
