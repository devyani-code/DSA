#include <stdio.h>

struct link
{
    int val;
    struct link* next;
    /* data */
};


int main(){
    int n,i=0;
    struct link* head=NULL;
    head=(struct link*)malloc(sizeof(struct link));
    struct link* temp=head;
    printf("n? \n");
    scanf("%d",&n);
    head->val=arr[0];
    printf("%d",arr[0]);
    for(i=1;i<n;i++){
      temp->next=(struct link*)malloc(sizeof(struct link));
      temp->next->val=arr[i];
      temp=temp->next;
    }
    
    

}