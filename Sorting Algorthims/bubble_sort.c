#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    printf("\n");
    int arr[n];
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    int j;
    for(k=0;k<n;k++){
        for(j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    

}