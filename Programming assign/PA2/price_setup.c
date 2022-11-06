/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node{

    struct node* left;

    struct node* right;

    int price;

    int ID;

    char name[100];

    char company_name[100];

    int camera_mp;

    char colour[100];

    int RAM;

    int batter_bp;

    int removable_bat;
};


int count=0;


struct node* new_node(char mobile_name[100], int val,char company_name[100], int camera_mp, char colour[100], int ram, int battery, int removable_bat ){

    struct node* temp= (struct node*)malloc(sizeof(struct node));

    temp->price=val;  

    strcpy(temp->name,mobile_name);
    strcpy(temp->company_name,company_name);
    strcpy(temp->colour,colour);

    temp->camera_mp=camera_mp;

    temp->RAM=ram;
    
    temp->batter_bp=battery;

    temp->removable_bat=removable_bat;

    temp->ID=count;

    temp->right=NULL;

    temp->left=NULL;
}
int height(struct node* root){
    if(root==NULL){
        return -1;
    }
    else{
        int lefth=height(root->left);
        int righth=height(root->right);

        if(lefth>righth){
            return(lefth+1);
        }
        else{
            return(righth+1);
        }
    }
}
int balance_factor(struct node* root){
    if(root==NULL){
        return -1;
    }
    else{
        return(height(root->left)-height(root->right));
    }
} 



struct node* right_rotate(struct node*root){
    struct node* p1=root->left;
    struct node* t2=p1->right;
    p1->right=root;
    root->left=t2;
    return p1;
}

struct node* left_rotate(struct node*root){
    struct node *y = root->right;
    struct node *T2 = y->left;
    y->left = root;
    root->right = T2;
    return y;
}

struct node* search_price(struct node* root,int val){
    if(root==NULL){
        printf("Not found");
        return root;
    }
    if(root->price==val){
        printf("%d,%s,%d,%s,%d,%s,%d,%d,%d",root->ID,root->name,root->price,root->company_name,root->camera_mp,root->colour,root->RAM,root->batter_bp,root->removable_bat);
        return root;
    }
    if(root->price>val){
        return search_price(root->left,val);
    }

    if(root->price<val){
        return search_price(root->right,val);
    }

}


struct node* insert_node_price(struct node*root,char mobile_name[100],int val, char company_name[100], float camera_mp, char colour[100], int ram, int battery, int removable_bat){
    if(root==NULL){
        return new_node(mobile_name,val,company_name,camera_mp,colour,ram,battery,removable_bat);
    }
    if(val<root->price){
        root->left=insert_node_price(root->left,mobile_name,val,company_name,camera_mp,colour,ram,battery,removable_bat);
    }
    if(val>root->price){
        root->right=insert_node_price(root->right,mobile_name,val,company_name,camera_mp,colour,ram,battery,removable_bat);
    }
    int balance_fac=balance_factor(root);
    if (balance_fac>1 && val<root->left->price){
        return right_rotate(root);
    }
    if(balance_fac<-1 && val>root->right->price){
        return left_rotate(root);
    }
    if(balance_fac>1 && val>root->left->price){
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance_fac<-1 && val<root->right->price){
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
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


void swap_data(char *str1, char *str2)
{
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
  free(temp);
}  

struct node* delete_price(struct node*ptr,int val){

    if(ptr==NULL){
        printf("Not found");
        return NULL;
    }
    else if(val<ptr->price){
        ptr->left=delete_price(ptr->left,val);
    }
    else if(val>ptr->price){
        ptr->right=delete_price(ptr->right,val);

    }
    else{
        if(ptr->left==NULL && ptr->right==NULL){
            printf("ok");
            free(ptr);
            ptr=NULL;
        }
        else if(ptr->right==NULL){
            struct node*temp;
            temp=ptr->left;
            free(ptr);
            return temp;
        }
        else if(ptr->left==NULL){
            struct node*temp;
            temp=ptr->right;
            free(ptr);
            return temp;
        }
        else{
            
            if(ptr->left!=NULL){
                 struct node* temp1=maximum_node(ptr->left);
                 ptr->price=temp1->price;
                 strcpy(ptr->name, temp1->name);
                 strcpy(ptr->company_name, temp1->company_name);
                 strcpy(ptr->colour, temp1->colour);
                 ptr->camera_mp=temp1->camera_mp;
                 ptr->batter_bp=temp1->batter_bp;
                 ptr->RAM=temp1->RAM;
                 ptr->removable_bat=temp1->removable_bat;
                 ptr->left=delete_price(ptr->left,temp1->price);
            }
            else if(ptr->right!=NULL){
                 struct node* temp1=minimum_node(ptr->right);
                 ptr->price=temp1->price;
                 strcpy(ptr->name, temp1->name);
                 strcpy(ptr->company_name, temp1->company_name);
                 strcpy(ptr->colour, temp1->colour);
                 ptr->camera_mp=temp1->camera_mp;
                 ptr->batter_bp=temp1->batter_bp;
                 ptr->RAM=temp1->RAM;
                 ptr->removable_bat=temp1->removable_bat;
                 swap_data(ptr->name,temp1->name);
                 ptr->right=delete_price(ptr->right,temp1->price);
            }
            
        }

    }
    int bf=balance_factor(ptr);
    if( bf==2 && balance_factor(ptr->left)>=0){
        return right_rotate(ptr);
    } 
    else if(bf==2 && balance_factor(ptr->left)==-1){
        ptr->left=left_rotate(ptr->left);
        return right_rotate(ptr);
    }
    else if(bf==-2 && balance_factor(ptr->right)<=0){
        return left_rotate(ptr);
    }
    else if(bf==-2 && balance_factor(ptr->right)==1){
        ptr->right=right_rotate(ptr->right);
        return left_rotate(ptr);
    }
    return ptr;
}
int main(){
    struct node* head_price= NULL;
    struct node* head_name=NULL;
 
   
    char input[100];


    // scanf("%[^\n]s",input);
    // getchar();

    // char *op = ?
    // char *mobile_name = strtok(NULL, ",");
    // int price = atoi(strtok(NULL, ", "));
    // char *company_name = strtok(NULL, ", ");
    // float camera_mp = atof(strtok(NULL, ", "));
    // char *colour = strtok(NULL, ", ");
    // int ram = atoi(strtok(NULL, ", "));
    // int battery_bp = atoi(strtok(NULL, ", "));
    // int removable_batt = atoi(strtok(NULL, ""));
    // printf("%s\n%s\n%d\n%s\n%f\n%s\n%d\n%d\n%d\n", op, mobile_name, price, company_name, camera_mp, colour, ram, battery_bp, removable_batt);
    count+=1;
    head_price=insert_node_price(head_price,"Nokia 6.2",12000,"Nokia",24,"Grey",8,30000,0);
    count+=1;
    head_price=insert_node_price(head_price,"samsung 6.2",15000,"samsung",12,"blue",8,20000,0);
    count+=1;
    head_price=insert_node_price(head_price,"iphone",14000,"apple",48,"white",12,40000,1);
    head_price=delet_
    printf("%s",head_price->name);

    // head_price=insert_node_price(head_price,15000,"micromax","micro",12,"white",12,40000,1);
    // count+=1;
    // head_price=insert_node_price(head_price,17000,"iphone","micromax",16,"black",12,40000,1);
    // head_price=search_price(head_price,10000);
    
}

