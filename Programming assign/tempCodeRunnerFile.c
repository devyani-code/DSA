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
        for(i=0;i<n;i++){
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