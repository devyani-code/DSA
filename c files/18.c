#include <stdio.h>


int main(){
    int mark[5] = {19, 10, 8, 17, 9};
    int mark1[5]={15,20,12,11,2};
    int sum[5];
    int *p, *q,i;
    p=mark;
    q=mark1;
    while(i<5){
        sum[i]=*(p+i)+*(q+i);
        printf("%d \n",sum[i]);
        i++;
    }
}