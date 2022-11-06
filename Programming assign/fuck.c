#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char url[100];
    struct node *next;
    struct node *prev;
};
 
struct node *curr_url = NULL;

void visit(struct node** head_ref, char addurl[100])
{
    struct node* newpage = (struct node*)malloc(sizeof(struct node));
    strcpy(newpage->url,addurl);
    
    newpage->next = NULL;
    struct node* temp = *head_ref;
    if (*head_ref == NULL) 
    {
        newpage->prev = NULL;
        *head_ref = newpage;
        curr_url=newpage;
        return;
    }
    /*while (temp->next != NULL)
    {
        temp = temp->next;
    }*/
    //printf("%s",curr_url->url);
    curr_url->next = newpage;
    newpage->prev = curr_url;
    curr_url=newpage;
    
}
void printList(struct node* n)
{   

    if(n->prev==NULL)
    {
        printf("none");
    }
    else
    {
        printf("%s",n->prev->url);
    } 
    
    printf(" %s",n->url);
   
    if (n->next==NULL)
    {
        printf(" none");
    }
    else
    {
        printf(" %s",n->next->url);
    } 
    
    
}

void main()
{
    struct node *head_ref =NULL;
    
    int k=1;

 
    while(k!=-1)
    {   
        char ch;
        char url[100];
        scanf("%c",&ch);
        gets(url);
        if (url[0] == ' ') 
           { memmove(url, url+1, strlen(url)); }
        switch(ch)
        {
            case 'V':
                {
                    visit(&head_ref,url);
                    printList(curr_url);
                    printf("\n");
                    break;
                }
            case 'B':
                {
                    int c=0;
                    int m = atoi(url);
                    for (int i=0; i<m;i++)
                    {   
                        if(curr_url!=NULL)
                        {c=1;}
                        if(curr_url->prev!=NULL)
                        {
                            curr_url=curr_url->prev;
                            c+=1;
                        }

                        else
                        {
                            printf("%d back not possible\n",m-i);
                            break;
                        }
                    }
                    printList(curr_url);
                    printf("\n");
                    break;
                }
            case 'F':
                {   int cnt=0;
                    int x = atoi(url);
                    for (int i=0; i<x;i++)
                    {
                        if(curr_url!=NULL)
                        {cnt=1;}
                        if(curr_url->next!=NULL)
                        {
                            curr_url=curr_url->next;
                            cnt+=1;
                        }
 
                        else
                        {
                            printf("%d forward not possible\n",x-i);
                            break;
                        }
                    }
                    printList(curr_url);
                    printf("\n");
                    break;
                }
            case 'Q':
                {   
                    struct node * temp_url=NULL;
                    int q = atoi(url);
                    temp_url=curr_url;
                //--------------------    
                    if(q>0)
                    {  
                        for (int i=0; i<abs(q);i++)
                        {
                            if(temp_url->next!=NULL)
                            {
                                temp_url=temp_url->next;
                            }
                            else if(temp_url==NULL)
                            {
                                printf("none\n");
                                break;
                            }
                        }
                        printf("%s\n",temp_url->url);
                    }
                //-------------------
                    if(q<0)
                    {
                        for (int i=0; i<abs(q);i++)
                        {
                            if(temp_url->prev!=NULL)
                            {
                                temp_url=temp_url->prev;
                            }
                            else if(temp_url==NULL)
                            {
                                printf("none\n");
                                break;
                            }
                        }
                        printf("%s\n",temp_url->url);
                    }
            //-------------------------------------
                    break;
                }
            case 'D':
                {   
                    int d = atoi(url);
                    if(d>0)
                    {   int c=0;
                        for (int i=0; i<abs(d);i++)
                        {
                            if(curr_url->next!=NULL)
                            {
                                curr_url=curr_url->next;
                                //printf("~~%s~~\n",curr_url);
                                c+=1;
                                
                            }
                            else
                            {
                                printf("none\n");
                                break;
                            }
                        }
                        if(c==abs(d))
                        
                        {   
                            if(curr_url->next!=NULL)
                            {
                                curr_url->next->prev=curr_url->prev;
                            }

                            if(curr_url->prev!=NULL)
                            {   
                                curr_url->prev->next=curr_url->next;
                                curr_url=curr_url->prev;
                            }


                        }
                        else
                        {   
                            for(int i=0; i<c;i++)
                            {
                                curr_url=curr_url->prev;
                            }
                        }
                    }
                //-------------------
                    if(d<0)
                    {int c=0;
                        for (int i=0; i<abs(d);i++)
                        {
                            if(curr_url->prev!=NULL)
                            {
                                curr_url=curr_url->prev;
                                c+=1;
                            }
                            else
                            {
                                printf("none\n");
                                break;
                            }
                        }
                        
                        if(c==abs(d))
                        {    if(curr_url->next!=NULL)
                            {
                                curr_url->next->prev=curr_url->prev;
                            }

                            if(curr_url->prev!=NULL)
                            {
                                curr_url->prev->next=curr_url->next;
                                curr_url=curr_url->prev;
                            }

                        }
                        else
                        {
                            for(int i=0; i<c;i++)
                            {
                                curr_url=curr_url->next;
                            }
                        }
                        
                    }

                    break;
                }
            case 'E':
                {
                    k=-1;
                    exit;
                }
            default:
                {
                    break;
                }
                
                
        }
    }
    
}