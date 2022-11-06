#include <stdio.h>
int main(){
    char str[1000];
    int j,i;
    int c=0;
    printf(" enter the string");
    scanf("%s",&str);
    while(str[j]!='\0'){
        c++;
        j++;
    }
    i=c;
    while(str[i-1]!='\0'){
        printf("%c",str[i-1]);
        i--;
    }
}