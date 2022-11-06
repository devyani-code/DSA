#include<stdio.h>

int insertion(int arr[],int n){
    int i=0;
    int val;
    int hole;
    for(i=0;i<n;i++){
        val=arr[i];
        hole= i;
        while(i>0 && arr[hole-1]>val ){
            arr[hole]=arr[hole-1];
            arr[hole-1]=val;
            hole=hole-1;
        }
    }
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}

int main(){
    int n;
    scanf("%d\n",&n);
    int arr[n];
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertion(arr,n);

}