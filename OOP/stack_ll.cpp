#include<iostream>
using namespace std;

class Node(){
    public:
        int data;
        Node*next;
        //parametrized constructor
        Node newnode(int data){
            this->data=data;
            next=NULL;
        }
};

class Stack(){
    
}