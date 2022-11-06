#include <stdio.h>
int main(){
    char str[1000];
    int len;
    printf("Enter the string");
    scanf("%s",&str);
    len=printf("%s\n",str);
    printf("%d",len-1);
}

// nulll string ='\0'