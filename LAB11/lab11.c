#include <stdio.h>
#include <math.h>

int dfs(int m,int n,int arr[][n],int row,int col){

    if(row<0 || col<0 || row>m || col>n){
        return 0;
    }
    if(arr[row][col]!=0){
        return 0;
    }

    arr[row][col]=-1;

    dfs(m,n,arr,row+1,col);
    dfs(m,n,arr,row-1,col);
    dfs(m,n,arr,row,col+1);
    dfs(m,n,arr,row,col-1);
    dfs(m,n,arr,row+1,col+1);
    dfs(m,n,arr,row-1,col-1);
    dfs(m,n,arr,row-1,col+1);
    dfs(m,n,arr,row+1,col-1);
}

int print(int m,int n, int arr[][n]){
    int i,j;
    printf("Replaced\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]==0){
                printf("%d %d\n",i,j);
            }
        }
    }
    printf("Not Replaced\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]==-1){
                printf("%d %d\n",i,j);
            }
        }
    }
}

void max_depth( int m, int n,int arr[][n], int x, int y)
{
    int max = 0;
    int max_x = 0;
    int max_y = 0;
    
    int i =0;
    int j=0;
    printf("Maximum Depth\n");
    
    while(i!=n)
    {
        while(j!=m)
        {
            
            if(arr[i][j]==-1)
            {
                int d = sqrt(((x-i)*(x-i))+((y-j)*(y-j)));
                if(d>max)
                {
                    max = d;
                    max_y = j;
                    max_x = i;
                }
            }
            
            i++;
            j++;
        }
    }
    printf("%d %d\n", max_x, max_y);
}

int main(){
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int arr[m][n];
    int i=0;
    int j=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i==0 || i==m-1){
                if(arr[i][j]==0){
                    dfs(m,n,arr,i,j);
                }
            }

    }

    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(i==0 || i==n-1){
                if(arr[j][i]==0){
                    dfs(m,n,arr,j,i);
                }
            }
    }
    }
    print(m,n,arr);
    for(i=0;i<m;i++){
        if(arr[i][0]==-1){
            max_depth(m,n,arr,i,0);
        }
        
    }
    for(i=0;i<n;i++){
        if(arr[0][i]==-1){
            max_depth(m,n,arr,0,i);
        }
    }
    for(i=0;i<n;i++){
        if(arr[m-1][i]==-1){
            max_depth(m,n,arr,m-1,i);
        }
    }
    for(i=0;i<m;i++){
        if(arr[i][n-1]==-1){
            max_depth(m,n,arr,i,n-1);
        }
    }

    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]==0){
                arr[i][j]=1;
            }
            else if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
    
}

