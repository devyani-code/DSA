#include <stdio.h>
void func(int a, int b){
    int *pa,*pb,c;
    pa=&a;
    pb=&b;
    c=*pa + *pb;
    printf("%d",c);
}

int main(){
   void (*func_ptr)(int, int) = &func;
   (*func_ptr)(10,11);
   return 0;
}