#include<iostream>
using namespace std;

class Stack{
    struct Node{
        int data;
        Node* next;
        Node*prev;

        //Constructor;
        Node(int num){
            this->data=num;
            this->next=nullptr;
            this->prev=nullptr;

        }
    };
    Node*head=nullptr;
    Node*top=nullptr;
    Node*mid=nullptr;
    int size=0;

    public:

        void push(int data ){
            
            if(size==0){
                Node*temp=new Node(data);
                head=temp;
                mid=temp;
                top=temp;
                size++;
                return;
            }

            Node*temp=new Node(data);

            top->next=temp;
            temp->prev=top;

            top=top->next;

            if(size%2==1){
                mid=mid->next;
            }
            size++;

        }

        int pop(){
            if(size==0){
                cout<<"Underflow";
                return -1;
            }
            Node*temp=top;
            top=top->prev;
            size--;
            if(size%2==1){
                mid=mid->prev;
            }
            return temp->data;

        }

        int findmiddle(){
            if(head==nullptr){
                return -1;
            }
            return mid->data;

        }

        void deletemiddle(){
            if(head==nullptr){
                return;
            }

            if(size==1){
                top=nullptr;
                mid=nullptr;
                return;
            }
            else if(size==2){
                top=top->prev;
                mid=mid->prev;
                top->next=NULL;
            }
            mid->prev->next=mid->next;
            mid->next->prev=mid->prev;

            if(size%2==0){
                mid=mid->prev;
            }
            else{
                mid=mid->next;
            }
            size--;

           
        }



};

int main()
{
    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.findmiddle() << endl;
    st.deletemiddle();
    cout <<"New Middle Element : "<< st.findmiddle() << endl;
    return 0;
}