#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;

};
struct node* root=NULL;
struct node* tail=NULL;
int count=0;

void print_fun(){
    struct node*pointer=root;
    while(pointer!=NULL){
      printf("%d ",pointer->data);
      pointer=pointer->next;
    }
    
}

struct node* enqueue(int val){
    if(root==NULL){
        struct node * newnode =(struct node*)malloc(sizeof(struct node));
        newnode->data=val;
        newnode->next=NULL;
        newnode->prev=NULL;
        root=newnode;
        tail=newnode;
    }
    else{
        struct node * newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=val;
        newnode->prev=tail;
        newnode->next=NULL;
        tail->next=newnode;
        tail=tail->next;

    }
    count+=1;
    return tail;
}

void dequeue(struct node* ptr){
    if(ptr==root){
        root=root->next;
        root->prev=NULL;
        free(ptr);
    }
    else if(ptr->next!=NULL && ptr->prev!=NULL){
        ptr->next->prev=ptr->prev;
        ptr->prev->next=ptr->next;
        free(ptr);
    }
    else if(ptr->next==NULL){
        ptr->prev->next=NULL;
        tail=tail->prev;
        free(ptr);
    }
    count-=1;
}
                     

int main(){
    int N;
    int m;
    int l;
    scanf("%d",&N);
    scanf("%d",&m);
    scanf("%d",&l);
    int i=0;
    int store_val[l];
    for(i=0;i<l;i++){
        scanf("%d",&store_val[i]);
        
    }
    int hash_int[N+1];

    struct node* hash_ptr[N+1];
    for(i=0;i<N+1;i++){
        hash_int[i]=0;
    }
    for(i=0;i<N+1;i++){
        hash_ptr[i]=NULL;
    }
    
    for(i=0;i<l;i++){
        if(hash_int[store_val[i]]==0){
            if(count<m){
            struct node* cute=enqueue(store_val[i]);
            print_fun();
            printf("\n");
            hash_int[store_val[i]]+=1;
            hash_ptr[store_val[i]]=cute;
            }
            else{
                struct node*temp1=root;
                dequeue(temp1);
                hash_int[temp1->data]-=1;
                struct node*temp=enqueue(store_val[i]);
                print_fun();
                printf("\n");
                hash_int[store_val[i]]+=1;
                hash_ptr[store_val[i]]=temp;

            }
        }
        else{
            struct node* sweet=hash_ptr[store_val[i]];
            dequeue(sweet);
            hash_int[store_val[i]]-=1;
            struct node* cute=enqueue(store_val[i]);
            print_fun();
            printf("\n");
            hash_int[store_val[i]]+=1;
            hash_ptr[store_val[i]]=cute;
        }

    }
}
    