#include <stdio.h>
#include <string.h>
char node_mat[20][4];
int store(int edge, char node_mat[][4], char str[4])
{
    int i;
    int n = edge;

    if (str[0] == 'S')
    {
        i = n - (str[1] - '0');
        strcpy(node_mat[i], str);
        return i;
    }
    else
    {
        if (str[1] == 'C')
        {
            strcpy(node_mat[0], str);
            return 0;
        }
        else
        {
            i = str[1] - '0';
            strcpy(node_mat[i], str);
            return i;
        }
    }
}

int find_min_index(int edge, int main_array[])
{
    int i;
    int minimum = 100;
    int index_min;
    for (i = 1; i < edge; i++)
    {
        if (main_array[i] < minimum)
        {
            minimum = main_array[i];
            index_min = i;
        }
    }
    return index_min;
}

void print_path(int arr[], int index)
{
    if (arr[index] == -1)
        return;

    print_path(arr, arr[index]);

    printf("%s ", node_mat[index]);
}

void print_distance(int edge,int distance[edge],int node_index,int pred[edge]){
    printf("%d ", distance[node_index]);
    printf("RC ");
    pred[0]=-1;
    print_path(pred, node_index);
    printf("\n");

}

void dijkstra(int edge,int mat[edge][edge], int start,int node_index) {
  int cost[edge][edge], distance[edge], pred[edge];
  int visited[edge], mindistance, nextnode, i=0, j=0;
    int n=edge;
  
  while(i<edge){
      j=0;
      while(j<edge){
          if (mat[i][j] == 0){
        cost[i][j] = 1000;
      }
       else{
       cost[i][j] = mat[i][j];
       }
       j++;
      }
      i++;
  }
  i=0,j=0;
  while(i<edge) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
    i++;
  }

  distance[start] = 0;
  visited[start] = 1;

  for(int count=1;count<n;count++) {
    mindistance = 1000;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
   
  }

  // Printing the distance
    print_distance(edge,distance,node_index,pred);
}

int main()
{
    int edge;

    char client[4];

    char server[4];

    int weight;
    scanf("%d", &edge);
    int i, j;
    int adj_mat[edge][edge];
    for (i = 0; i < edge; i++)
    {
        for (j = 0; j < edge; j++)
        {
            adj_mat[i][j] = 1000;
        }
    }
    int x;

    int y;

    char third = 'S';

    scanf("%s", client);

    x = store(edge, node_mat, client);
    // printf("%d\n",x);
    scanf("%s", server);

    y = store(edge, node_mat, server);
    // printf(" %d",y);
    scanf("%d", &weight);

    adj_mat[x][y] = weight;
    adj_mat[y][x] = weight;

    while (1)
    {
        scanf("%s", client);
        if (client[0] == third)
        {
            break;
        }
        x = store(edge, node_mat, client);
        scanf("%s", server);
        y = store(edge, node_mat, server);

        scanf("%d", &weight);

        adj_mat[x][y] = weight;
        adj_mat[y][x] = weight;
    }
    strcpy(server, client);
    x = store(edge, node_mat, server);
   
    dijkstra(edge, adj_mat, 0, x);
    
    while (1)
    {
        scanf("%s", server);
        if (server[0] == 'T')
        {
            break;
        }
        x = store(edge, node_mat, server);
        dijkstra(edge, adj_mat, 0,x);
    }

    
}