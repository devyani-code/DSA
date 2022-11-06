#include <stdio.h>
#include<stdlib.h>
int moves;
int cost(int size, int matrix[size][size], int target[size][size])
{
    int count=0,i=0, j = 0;
     for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(matrix[i][j] && matrix[i][j]!=target[i][j]){
                    count++;
                }
            }
        }
    return count;
}
int check_if_same(int size, int matrix[size][size], int target[size][size])
{
    int i=0, j = 0;
    int flag=1;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (target[i][j] != matrix[i][j])
            {
                flag=0;
            }
            j++;
        }
        i++;
    }
    return flag;
}

void display(int size, int arr[size][size]){
    for(int i =0;i<size;i++){
        for(int j =0;j<size;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int bfs(int size, int inp_matrix[size][size],int targ_matrix[size][size])
{
    int x0, y0, i, j;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(inp_matrix[i][j]==0){
                x0 =i;y0=j;
                break;
            }
        }
    }
    // printf("%d\n",y0);
    int arr[size][size];
    int cost_arr[4];
    int left_arr[size][size];
    int right_arr[size][size];
    int up_arr[size][size];
    int down_arr[size][size];
    cost_arr[0]=-1;
    cost_arr[1]=-1;
    cost_arr[2]=-1;
    cost_arr[3]=-1;
    // to move left
    if (y0 != 0)
    {
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                left_arr[i][j]=inp_matrix[i][j];
            }
        }

        int shift = left_arr[x0][y0];
        int num = left_arr[x0][y0 - 1];
        left_arr[x0][y0] = num;
        left_arr[x0][y0 - 1] = shift;
        // printf("left shift:\n");
        // display(size,left_arr);
        cost_arr[0]=cost(size,left_arr,targ_matrix);
        // printf("cost = %d\n",cost_arr[0]);

    }
    // to move right
    if (y0 != size - 1)
    {
        
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                right_arr[i][j]=inp_matrix[i][j];
            }
        }
        int shift = right_arr[x0][y0];
        int num = right_arr[x0][y0 + 1];
        right_arr[x0][y0] = num;
        right_arr[x0][y0 + 1] = shift;
        // printf("right_arr:\n");
        // display(size,right_arr);
        
        cost_arr[1]=cost(size,right_arr,targ_matrix);
        // printf("cost = %d\n",cost_arr[1]); 
        
    }
    if (x0 != 0)
    {
        
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                up_arr[i][j]=inp_matrix[i][j];
            }
        }
        int shift = up_arr[x0][y0];
        int num = up_arr[x0-1][y0];
        up_arr[x0][y0] = num;
        up_arr[x0-1][y0] = shift;
        cost_arr[2]=cost(size,up_arr,targ_matrix);
        // printf("up_arr:\n");
        // display(size,up_arr);
        // printf("cost = \n",cost_arr[2]);
        
    }
    if (x0 != size-1)
    {
        
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                down_arr[i][j]=inp_matrix[i][j];
            }
        }
        int shift = down_arr[x0][y0];
        int num = down_arr[x0+1][y0];
        down_arr[x0][y0] = num;
        down_arr[x0+1][y0] = shift;
        // printf("down_arr:\n");
        // display(size,down_arr);

        cost_arr[3]=cost(size,down_arr,targ_matrix);
        // printf("cost=%d\n",cost_arr[3]);
    }
    int min=10000;
    int min_index=0;
    for(i=0;i<4;i++){
        if(cost_arr[i]!=-1 && cost_arr[i]<min){
            min=cost_arr[i];
            min_index=i;
        }
    }
    if(cost_arr[min_index]==cost_arr[0]){
        moves++;
        if(check_if_same(size,left_arr,targ_matrix)==1){
            return moves;
        }
        bfs(size,left_arr,targ_matrix);
    }
    else if(cost_arr[min_index]==cost_arr[1]){
        moves++;
        if(check_if_same(size,right_arr,targ_matrix)==1){
            return moves;
        }
        bfs(size,right_arr,targ_matrix);
    }
    else if(cost_arr[min_index]==cost_arr[2]){
        moves++;
        if(check_if_same(size,up_arr,targ_matrix)==1){
            return moves;
        }
        bfs(size,up_arr,targ_matrix);
    }
    else if(cost_arr[min_index]==cost_arr[3]){
        moves++;
        if(check_if_same(size,down_arr,targ_matrix)==1){
            return moves;
        }
        bfs(size,down_arr,targ_matrix);
    }

}

int main()
{
    int size;
    scanf("%d", &size);
    int inp_mat[size][size];
    int targ_matrix[size][size];
    int i, j = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            scanf("%d", &inp_mat[i][j]);
        }
    }
    int count = 1;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            targ_matrix[i][j] = count++;
        }
    }
    targ_matrix[size - 1][size - 1] = 0;
    moves = bfs(size,inp_mat,targ_matrix);
    printf("%d",moves);
}