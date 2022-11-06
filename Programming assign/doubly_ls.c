#include <stdio.h>

struct l1{
    int val;
    struct l1* next;
    struct l1* prev;
};

int main(){
    int n,i=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    struct l1*head=NULL;
    head=(struct l1*)malloc(sizeof(struct l1));
    struct l1*temp=head;
    head->val=arr[0];
    temp->prev=NULL;
    for(i=1;i<n;i++){
            temp->next=(struct l1*)malloc(sizeof(struct l1));
            temp->next->val=arr[i];
            temp->next->prev=temp;
            temp=temp->next;
    }
    temp->next=NULL;
    temp=head;
    printf("%d",temp->next->next->prev->val);
}