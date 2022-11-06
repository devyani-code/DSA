#include <stdio.h>
int main(){
    int q ,r;
    int i,j;
    int ans=0,c=1;
    char str[100];
    printf("Enter the integer \n");
    scanf("%d",&q);
    while(q>0){
        r=q%2;
        q=q/2;
        for(j==0;j<i;j++){
            c*=10;
        }
        ans+=c*r;
        i++;
    }
    printf("%d",ans);

}