#include <stdio.h>

int main(){
    float x;
    int n,i;
    double c=1;
    printf("enter exponent \n");
    scanf("%f",&x);
    printf("Enter power \n");
    scanf("%d",&n);
    for(i==0;i<(n);i++){
        c*=x;
    }
    printf("answer is %f",c);
}