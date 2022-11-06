#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct l1{
    int val;
    struct l1* next;
};

struct l1* head=NULL;

struct l1* top(){
    struct l1*head_ref;
    struct l1* top;
    head_ref=head;
    top=head_ref;
    while(top->next!=NULL){
      top=top->next;
    }
    return top; 
    // returns pointer pointing to the last node
}

int push(int x){
    struct l1* head_ref;
    struct l1*temp;
    head_ref=head;
    temp=top();
    temp->next=(struct l1*)malloc(sizeof(struct l1));
    temp->next->val=x;
    temp=temp->next;
    temp->next=NULL;

    // temp points the last node which is the top now
}

struct l1* pop(){
    struct l1* head_ref;
    struct l1* top_ref;
    struct l1* temp;
    head_ref=head;
    top_ref=top();
    temp=head_ref;
    while(temp->next->next!=NULL){
      temp=temp->next;
    }
      temp->next=NULL;
    top_ref=temp;
    return top_ref;

}

int power(int x, int b){
  int i;
  int sum=1;
  for(i=0;i<b;i++){
    sum*=x;
  }
  return sum;
}

int strtoint(char* Str[100],int i){
    char ptr[2];
    int x;
    ptr[0]=Str[i];
    ptr[1]='\0';
    x=atoi(ptr);
    return x;
}
 
int main()
{
    char* Str[100];
    int len,i,j;
    printf("Enter the String: ");
    scanf("%s", Str);
    len=strlen(Str);
    char ptr[2];
    printf("%d",len);
    head=(struct l1*)malloc(sizeof(struct l1));
    struct l1* temp=head;
    head->val=strtoint(Str,0);
    for(i=0;i<len;i++){
        if(Str[i]!=','){
            temp->next=(struct l1*)malloc(sizeof(struct l1))
            
        }
    }

}