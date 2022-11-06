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


struct node* new_node(char mobile_name[100],int val, char company_name[100], int camera_mp, char colour[100], int ram, int battery, int removable_bat ){

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



struct node* insert_name(struct node*root,char mobile_name[100],int val, char company_name[100], int camera_mp, char colour[100], int ram, int battery, int removable_bat){

    if(root==NULL){
        return new_node(mobile_name,val,company_name,camera_mp,colour,ram,battery,removable_bat);
    }
    if(strcmp(root->name,mobile_name)>0){
        root->left=insert_name(root->left,mobile_name,val,company_name,camera_mp,colour,ram,battery,removable_bat);
    }
    if(strcmp(root->name,mobile_name)<0){
        root->right = insert_name(root->right,mobile_name,val,company_name,camera_mp,colour,ram,battery,removable_bat);
    }
    int balance_fac=balance_factor(root);

    if (balance_fac>1 && strcmp(root->left->name,mobile_name)>0){
        return right_rotate(root);
    }
    if(balance_fac<-1 && strcmp(root->right->name,mobile_name)<0){
        return left_rotate(root);
    }
    if(balance_fac>1 &&  strcmp(root->left->name,mobile_name)<0){
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance_fac<-1 && strcmp(root->right->name,mobile_name)>0){
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

struct node* maximum_node(struct node* ptr){
    struct node*present=ptr;
    while(present->right!=NULL){
        present=present->right;
    }
    return present;
}

struct node* minimum_node(struct node* ptr){
    struct node*present=ptr;
    while(present->left!=NULL){
        present=present->left;
    }
    return present;
}

struct node* delete_name(struct node*ptr,char name[100]){
    if(ptr==NULL){
        return NULL;
    }
    else if(strcmp(ptr->name,name)>0){

        ptr->left=delete_name(ptr->left,name);
    }
    else if(strcmp(ptr->name,name)<0){
        ptr->right=delete_name(ptr->right,name);
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
                 ptr->left=delete_name(ptr->left,temp1->name);
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
                 ptr->right=delete_name(ptr->right,temp1->name);
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

struct node* search_name(struct node* root,char name[100]){
    if(root==NULL){
        printf("Not found");
        return root;
    }
    if(strcmp(root->name,name)==0){
        printf("%d,%s,%d,%s,%d,%s,%d,%d,%d",root->ID,root->name,root->price,root->company_name,root->camera_mp,root->colour,root->RAM,root->batter_bp,root->removable_bat);
        return root;
    }
    if(strcmp(root->name,name)>0){
        return search_name(root->left,name);
    }

    if(strcmp(root->name,name)<0){
        return search_name(root->right,name);
    }

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
    head_price=insert_name(head_price,"Nokia 6.2",12000,"Nokia",24,"Grey",8,30000,0);
    count+=1;
    head_price=insert_name(head_price,"asus",20000,"asu",24,"Grey",8,30000,0);
    count+=1;
    head_price=insert_name(head_price,"samsung 6.2",1000,"samsung",12,"blue",8,20000,0);
    count+=1;
    head_price=insert_name(head_price,"mcromax",5000,"micro",12,"white",12,40000,1);
    count+=1;
    head_price=insert_name(head_price,"zephyrus",5000,"zacro",12,"white",12,40000,1);
    head_price=delete_name(head_price,"asus");
    head_price=search_name(head_price,"zephyrus");
    
    
}

