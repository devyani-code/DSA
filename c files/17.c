#include <stdio.h>

void string_len(char str[100]){
    printf("enter the string: %s \n",str);
    char *point= str;
    int i,count=0;
    while(*point !='\0'){
        count+=1;
        *point++;
    }
    printf("%d",count);
}

int main(){

   void (*func_ptr)(char* )=&string_len;
   (*func_ptr)("Devyani");
}

void string_len2(char str[100]){
    printf("enter the string: %s \n",str);
    char** point=&str;
    int i,count=0;
    while(point[i] !='\0'){
        count+=1;
        i++;
    }
    printf("%d",count);
}

