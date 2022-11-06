#include <stdio.h>
int main(){
    int n=10;
    int *p;
    p=&n;
    printf("%x\n",p);
    printf("%d",*p);
}