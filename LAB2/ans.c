#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct link1{
    int val;
    int degree;
    struct link1* next;
};

int power(int x ,int b){
    int result=1;
    int i=0;
    for(i=0;i<b;i++){
        result*=x;
    }
    return result;

}

char sign(int x){
    if (x>0){
        return '+';
    }
    if(x<0){
        return '-';
    }
}

int main(){
   
        int n1,n2;
        int i=0;
        int x;
        int sum1=0,sum2=0;
        scanf("%d", &n1);
        int arr1[n1+1];
        while(i<n1+1){
            scanf("%d",&arr1[i]);
            i++;
        }
        scanf("%d", &n2);
        int arr2[n2+1];
        i=0;
        while(i<n2+1){
            scanf("%d",&arr2[i]);
            i++;
        }
        i=0;
        scanf("%d",&x);
        
        struct link1* head1 = NULL;
        head1=(struct link1*)malloc(sizeof(struct link1));
        struct link1* temp1=head1;
        head1->val=arr1[0];
        head1->degree=n1;
        for(i=1;i<n1+1;i++){
            temp1->next=(struct link1*)malloc(sizeof(struct link1));
            temp1->next->val=arr1[i];
            temp1->next->degree=n1-i;
            temp1=temp1->next;
        }
        temp1=head1;
        printf("P1(x) = ");
        if(n1==0){
            sum1+=arr1[0]*power(x,n1);
            printf("%d \n",(arr1[0]),n1);
        }
        else{
            sum1+=arr1[0]*power(x,n1);
            printf("%dx^%d ",(arr1[0]),n1);
        }

        for(i=1;i<n1+1;i++){
            if(i!=n1){
                if (arr1[i]!=0){
                    sum1+=arr1[i]*power(x,n1-i);
                    char c=sign(arr1[i]);
                    printf("%c %dx^%d ",c,abs(arr1[i]),n1-i);
                    
            }
        }
            if(i==n1){
                if(arr1[i]!=0){
                sum1+=arr1[i];
                char c=sign(arr1[i]);
                printf("%c %d \n",c,abs(arr1[i]));
                }
                else{
                    printf("\n");
                }
            }
        }
        struct link1* head2 = NULL;
        head2=(struct link1*)malloc(sizeof(struct link1));
        struct link1* temp2=head2;
        head2->val=arr2[0];
        head2->degree=n2;
        for(i=1;i<n2+1;i++){
            temp2->next=(struct link1*)malloc(sizeof(struct link1));
            temp2->next->val=arr2[i];
            temp2->next->degree=n2-i;
            temp2=temp2->next;
        }
        printf("P2(x) = ");
        if(n2==0){
            sum2+=arr2[0]*power(x,n2);
            printf("%d \n",(arr2[0]),n2);
        }
        else{
            sum2+=arr2[0]*power(x,n2);
            printf("%dx^%d ",(arr2[0]),n2);
        }
        for(i=1;i<n2+1;i++){
            if(i!=n2){
                if (arr2[i]!=0){
                    sum2+=arr2[i]*power(x,n2-i);
                    char c=sign(arr2[i]);
                    printf("%c %dx^%d ",c,abs(arr2[i]),n2-i);         
            }
        }
            else{
                if(arr2[i]!=0){
                sum2+=arr2[i];
                char c=sign(arr2[i]);
                printf("%c %d \n",c,abs(arr2[i]));
                }
                else{
                    printf("\n");
                }
            }
        }
        i=0;
        temp1=head1;
        temp2=head2;
        int arr3[n2+n1+2];
        int sum=0;
        for(i=0;i<n1+1;i++){
            temp1->degree+=(n2+1);
            if (i!=n1){
                temp1=temp1->next;     
                }
                }
            temp1->next=head2;
            temp1=head1;
            i=0;

            for(i=0;i<n2+n1+2;i++){
                int a=temp1->val;
                int b=temp1->degree;
                sum+=a*power(x,b);
                arr3[i]=a;
                temp1=temp1->next;
            }
       
        int p=n2+n1+1;
        printf("P3(x) = ");
        printf("%dx^%d ",(arr3[0]),p);
        for(i=1;i<n1+n2+2;i++){
            if(i!=p){
                if (arr3[i]!=0){
                    char c=sign(arr3[i]);
                    printf("%c %dx^%d ",c,abs(arr3[i]),p-i);
                    
            }
        }
            else{
                if (arr3[i]!=0){
                char c=sign(arr3[i]);
                printf("%c %d \n",c,abs(arr3[i]));
                }
                else{
                    printf("\n");
                }
            }
        }
        printf("P1(%d) = %d \n",x,sum1);
        printf("P2(%d) = %d \n",x,sum2);
        printf("P3(%d) = %d \n",x,sum);

}
