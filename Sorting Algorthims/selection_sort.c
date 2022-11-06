#include<stdio.h>

int find_minimum(int arr[],int start,int end){
    int min=0;
    int i=0;
    int n=end-start;
    for(i=start;i<end;i++){
        if(arr[i]<arr[min]){
            min=i;
        }
    }
    return min;

}

int selection_sort(int*arr,int n){
    int min_index;
    int i=0;
    int j;
    for(i=0;i<n-1;i++){
        min_index=find_minimum(arr,i,n);
        if(arr[i]>arr[min_index]){
            int temp=arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
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
    selection_sort(arr,n);
}