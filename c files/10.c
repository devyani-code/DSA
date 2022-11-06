#include <stdio.h>
int main(){
    unsigned char str1[1000],str2[1000];
    int j,i,k;
    int c=0;
    int ans=0;
    printf("enter the string \n");
    scanf("%s",&str1);
    while(str1[j]!='\0'){
        c++;
        j++;
    }
    while(str1[i]!='\0'){
        str2[i]=str1[c-i-1];
        i++;
        }
    for(k=0;k<c;k++){
        if(str1[k]==str2[k]){
            ans=1;
        }
        else{
            ans=0;
        }
    }
    printf("ans=%d",ans);
    
}
