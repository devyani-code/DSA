#include <stdio.h>

int concate(char string1[10], char string2[10]){
    char *p1=string1;
    char *p2=string2;
    int i,j;
    char s3[10];
    while(string1[i]!='\0'){
        s3[j]=*(p1+i);
        i++;
        j++;
    }
    i=0;
    while(string2[i]!='\0'){
        s3[j]=*(p2+i);
        i++;
        j++;
    }
    printf("%s",s3);
}
int main(){
    concate("eva","Gorkar");
}