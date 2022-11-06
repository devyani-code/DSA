#include<stdio.h>

#include<stdlib.h>

struct node{

    struct node* left;

    struct node* right;

    int val;

    int level;

    struct node* next;
};

struct node* root = NULL;

struct node* front=NULL;

struct node* rear=NULL;

struct node* top= NULL;

int lev=0;

struct node* enqueue(struct node* ptr){
    if(rear==NULL){
        front=rear=ptr;
        front->next=NULL;
    }
    else{
        rear->next=ptr;
        rear=rear->next;
    }

}

struct node* dequeue(){
 
 if (front==NULL){
    return 0; 
  }
 if (front==rear){
   front=rear=NULL;
   return 0;
   }
 struct node* ptr=NULL;
 ptr=front->next;
 front=ptr;
 
 if(front==NULL){
   front=rear=NULL;
  }

}

int push(struct node* ptr){
  ptr->next=top;
  top=ptr;

}

struct node* pop(){
    if(top==NULL){
        return 0;
    }
    else{
        top=top->next;
    }
    
}



int preorder(){
    struct node* temp=root;
    while(1){
        while(temp != NULL){
            printf("%d ",temp->val);
            push(temp);
            temp = temp->left;
        }
        if(temp == NULL && top!=NULL){
          struct node* ptr=top;
          pop();
          temp=ptr;
        }
        temp = temp->right;
        if(temp == NULL && top == NULL){
            break;
        }
    }
    printf("\n");
}


struct node* minimum_node(struct node* ptr){
    struct node*present=ptr;
    while(present->left!=NULL){
        present=present->left;
    }
    return present;
}

struct node* maximum_node(struct node* ptr){
    struct node*present=ptr;
    while(present->right!=NULL){
        present=present->right;
    }
    return present;
}

struct node* delete_node(struct node* ptr,int value){
    if(root==NULL){
        printf("empty\n");
    }
    else if(ptr==NULL){
      return NULL;
    }
    else if(value<ptr->val){
        ptr->left=delete_node(ptr->left,value);
    }
    else if(value>ptr->val){
        ptr->right=delete_node(ptr->right,value);
    }
    else if(value==ptr->val){
         if(ptr->left==NULL && ptr->right==NULL){
             free(ptr);
             ptr=NULL;
         }

         else if(ptr->left==NULL){
             struct node* temp=ptr;
             ptr=ptr->right;
             free(temp);
         }
         else if(ptr->right==NULL){
             struct node* temp=ptr;
             ptr=ptr->left;
             free(temp);
         }
         else{
            if(ptr->left!=NULL){
                 struct node* temp1=maximum_node(ptr->left);
                 ptr->val=temp1->val;
                 ptr->left=delete_node(ptr->left,temp1->val);
            }
            else if(ptr->right!=NULL){
                 struct node* temp1=minimum_node(ptr->right);
                 ptr->val=temp1->val;
                 ptr->right=delete_node(ptr->right,temp1->val);
            }
            
         }
        
    }
    return ptr;
}
int *PostOrd(int *arr){
    int i =0;
    struct node* temp=root;
    while(1){
        while(temp != NULL){
            *(arr+i) = temp->val;
            push(temp);
            i++;
            
            temp = temp->left;
        }
        if(temp == NULL && top!=NULL){
            struct node* ptr=top;
        	pop();
        	temp=ptr;
        }
        temp = temp->right;
        
        if(temp == NULL && top == NULL){
            break;
        }
    }
    return arr;
}

int count_leaf(struct node* ptr,int lev){
    int count=0;
    int arr[100]={0};
    arr[0]=1;
    int level = 0;
    enqueue(root);
    while(front!=NULL){
        struct node* temp;
        // struct node* temp2;
        if(front->left==NULL && front->right==NULL){
            count++;
        }
        if(front->right!=NULL){
            temp=front->right;
            enqueue(temp);
            arr[temp->level]++;
            
        }
        if(front->left!=NULL){
            temp=front->left;
            enqueue(temp);
            arr[temp->level]++;
        }
        dequeue();
        level++;
    }
    printf("%d \n",count);
    
    int countlevel = 0;
    for (int i = 0; arr[i]!='\0'; i++) {
        countlevel++;
    }
    printf("%d \n",countlevel);
}

int nodes_count(struct node* ptr,int lev){
    int arr[100]={0};
    arr[0]=1;
    int level=0;
    enqueue(root);
    while(front!=NULL){
        struct node* temp;
        // struct node*temp;
        if (front->left!=NULL){
            temp=front->left;
            enqueue(temp);
            arr[temp->level]++;
        }
        if(front->right!=NULL){
            temp=front->right;
            enqueue(temp);
            arr[temp->level]++;
        }
        dequeue();
        level++;
    }
    int i=0;
    for(i=0;i<level && arr[i]!= '\0';i++){
        printf("%d %d\n",i,arr[i]);
    }
    int countlevel = 0;
    for (int i = 0; arr[i]!='\0'; i++) {
        countlevel++;
    }
    return countlevel;
}

int create_bst(int arr[],int len){
    int i;
    root=(struct node*)malloc(sizeof(struct node));
    root->val=arr[len-1];
    root->right=NULL;
    root->left=NULL;
    root->level=0;
    int levelss[15];
    struct node* parent=NULL;
    struct node*temp=root;
    for(i=len-2;i>-1;i--){
        while(temp!=NULL){
            parent=temp;
            if(temp->val<arr[i]){
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
        }
        if(parent->val<arr[i]){
            parent->right=(struct node*)malloc(sizeof(struct node));
            parent->right->val=arr[i];
            parent->right->right=NULL;
            parent->right->left=NULL;
            parent->right->level=parent->level+1;
            levelss[i]=parent->level+1;
        }
        else{
            parent->left=(struct node*)malloc(sizeof(struct node));
            parent->left->val=arr[i];
            parent->left->right=NULL;
            parent->left->left=NULL;
            parent->left->level=parent->level + 1;
            levelss[i]=parent->level+1;
        }
        temp=root;
    }
    return levelss[0];
}

int main(){
    while(1){
        int input[2];

        int j = 0;

        do
        {
            scanf("%d", &input[j++]);
        } while (getchar() != '\n' && j < 2);

        if (input[0] == 1){

            int len;

            scanf("%d",&len);

            int arr_inorder[len];

            for (int j = 0; j<len; j++){

                scanf("%d",&arr_inorder[j]);

            }

            scanf("%d",&len);

            int arr_postorder[len];

            for (int j = 0; j<len; j++){

                scanf("%d",&arr_postorder[j]);

            }

            lev=create_bst(arr_postorder,len);
            count_leaf(root,lev);
            nodes_count(root,lev);

        }

        if (input[0] == 2){

            int removed = input[1];
            if(root == NULL){
                printf("empty\n");
            }
            else{
                int *postOrd = (int *)malloc(15 *sizeof(int));
                postOrd = PostOrd(postOrd);
                int flag = 0;
                
                for(int i = 0;i<15;i++){
                    if(removed == *(postOrd+i)){
                        flag = 1;
                    }
                }
                if(flag == 1){
                    delete_node(root, removed);
                    preorder();
                    
                   
                }
                else{
                    printf("error\n");
                }

            }
        }

        if (input[0] == -1){

            break;

        }
    }
    return 0;
    
}