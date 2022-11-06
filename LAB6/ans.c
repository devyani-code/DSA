#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int* multiply_poly(int p1[],int p2[],int n){
    int l = n;
    if (l==2){
      int *y = (int *)malloc(3*sizeof(int));
      y[0]=p1[0]*p2[0];
      y[1]=p2[1]*p1[0]+p2[0]*p1[1];
      y[2]=p2[1]*p1[1];
      return y;
    }
      
      int k = l/2;
      
      int a0[k];
      int b0[k];
      int a1[l-k];
      int b1[l-k];
      
      for(int i=0;i<k;i++){
          a0[i] = p1[i];
          b0[i] = p2[i];
          a1[i] = p1[i+k];
          b1[i] = p2[i+k];
      }
      int a0a1[k];
      int b0b1[k];
      
      for(int i=0;i<l-k;i++){
          a0a1[i] =a0[i]+a1[i];
          b0b1[i] =b0[i]+b1[i];
      }
      
      int *yx=multiply_poly(a0a1,b0b1,k - 1);
    
      int *ux=multiply_poly(a0,b0,l-k-1);
      
      int *zx=multiply_poly(a1,b1,l-k-1);
      
    int *arr = (int *)malloc((2*n +1)*sizeof(int));
    for (int i = 0; i < 2*n + 1 ; i++) {
        arr[i] =0;
    }
    int m = ceil(l/2);
    for(int i=0;i<l-1;i++){
        arr[i]=ux[i];
        arr[i+m]=yx[i]-ux[i]-zx[i];
        arr[i+2*m]=zx[i];
    }
    return arr;
}
int main(){
    
    int n;
    scanf("%d",&n);
    int p1[n];
    for(int i=0;i<n+1;i++){
        scanf("%d",&p1[i]);
    }
    int p2[n];
    for(int i=0;i<n+1;i++){
        scanf("%d",&p2[i]);
    }
    int *ans = multiply_poly(p1,p2,n);
    for (int i = 0; i < 2*n +1; i++) {
        printf("%d ",ans[i]);
    }
    return 0;
}