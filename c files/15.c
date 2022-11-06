#include <stdio.h>
int main(){
    int arr[7]={10,5,3,20,50,10,60};
    int i,j,temp;
    int n=7;
    for(i=n-1;i>-1;i--){
        for(j=i-1;j>-1;j--){
            if(arr[j]>arr[i]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }

    }
    for(i = 0; i<7; i++)    
    {    
        printf("%d\n",arr[i]);    
    }    
}