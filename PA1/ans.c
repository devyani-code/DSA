#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct l1{
    int val;
    char word[100];
    struct l1* next;
    struct l1* prev;
};
struct l1*head=NULL;
struct l1* rear=NULL;
int count=0;

void visit(int n,char str1[100]){
    if (head==NULL){
        head=(struct l1*)malloc(sizeof(struct l1));
        strcpy(head->word,str1);
        head->next=NULL;
        head->prev=NULL;
        head->val=0;
        printf("none %s none\n",head->word);
        rear=head;
    }
    
    else{
        rear->next=(struct l1*)malloc(sizeof(struct l1));
        strcpy(rear->next->word,str1);
        rear->next->next=NULL;
        rear->next->prev=rear;
        rear->next->val=n;
        rear=rear->next;
        printf("%s %s none\n",rear->prev->word,rear->word);
    
    }
    
    return ;
}


int forward(int n){
    int i=0;
    for(i=0;i<abs(n);i++){
        if(rear->next!=NULL){
            rear=rear->next;
        }
        else{
            printf("%d forward not possible\n",n-i);
            break;
        }
    }
    if(rear->next==NULL && rear->prev!=NULL){
            printf("%s %s none\n",rear->prev->word,rear->word);
    }
    if(rear->prev==NULL && rear->next!=NULL){
            printf("none %s %s\n",rear->word,rear->next->word);
    }
    if(rear->prev!=NULL && rear->next!=NULL){
        printf("%s %s %s\n",rear->prev->word,rear->word,rear->next->word);
    }
    if(rear->prev==NULL && rear->next==NULL){
        printf("none %s none\n",rear->word);
    }
    return 0;
}

int back(int n){
    int i;
    for(i=0;i<abs(n);i++){
        if(rear->prev!=NULL){
            rear=rear->prev;
        }
        else{
            printf("%d back not possible\n",n-i);
            break;
        }
    }
    if(rear->prev==NULL && rear->next!=NULL){
        printf("none %s %s\n",rear->word,rear->next->word);
    }
    if(rear->next==NULL && rear->prev!=NULL){
        printf("%s %s none\n",rear->prev->word,rear->word);
    }
    if(rear->prev!=NULL && rear->next!=NULL){
        printf("%s %s %s\n",rear->prev->word,rear->word,rear->next->word);
    }
    if(rear->prev==NULL && rear->next==NULL){
        printf("none %s none\n",rear->word);
    }
    
    
}

int show_url(int n){
    int i=0;
    struct l1* temp=rear;
    if(n>0){
        for(i=0;i<n;i++){
            if(temp->next!=NULL){
            temp=temp->next;
            }
            else{
                printf("none\n");
                return 0;
        }
      }
    }
    if(n<0){
        for(i=0;i<abs(n);i++){
            if(temp->prev!=NULL){
            temp=temp->prev;
            }
            else{
                printf("none\n");
                return 0;
            }
        }
    }
    printf("%s\n",temp->word);

}

int delete_url(int n){
    int i;
    struct l1*temp=rear;
    if(n>0){
        for(i=0;i<n;i++){
            if(temp->next!=NULL){
                temp=temp->next;
            }
            else{
                printf("none\n");
                return 0;
            }
        
        }
        if(temp->next==NULL){
            temp=temp->prev;
            temp->next=NULL;
        }
        else{
            struct l1* ptr;
            ptr=temp;
            temp=temp->next;
            temp->prev=ptr->prev;
            ptr->prev->next=temp;
            free(ptr);
        }
    }
if(n<0){
    for(i=0;i<abs(n);i++){
            if(temp->prev!=NULL){
                temp=temp->prev;
            }
            else{
                printf("none\n");
                return 0;
            }
    }
    if (temp==head){
        head=temp->next;
        temp=temp->next;
        temp->prev=NULL;
    }
    else{
        struct l1* ptr;
        ptr=temp;
        ptr->prev->next=temp->next;
        temp=temp->next;
        temp->prev=ptr->prev;
        free(ptr);
    }
    
}
}



int main(){
    while(1){
        char c;
        scanf("%c",&c);
        if(c=='E'){
            exit(0);
        }
        if(c=='V'){
            char str[100];
            scanf("%s",&str);
            visit(count,str);
            count++;
        }
        if(c=='B'){
            int x;
            scanf("%d",&x);
            back(x);
        }
        if(c=='F'){
            int x;
            scanf("%d",&x);
            if(x>=0){
                forward(x);
            }
            if(x<0){
                back(x);
            }
        }
        if(c=='Q'){
            int x;
            scanf("%d",&x);
            show_url(x);
        }
        if(c=='D'){
            int x;
            scanf("%d",&x);
            delete_url(x);
        }

    }
}