#include<bits/stdc++.h>
using namespace std;

class Stack{
    int top;

    public:
        int a[100];
        top=-1;
        void push(int x){
            if(top>=100-1){
                cout<<"Stack Overflow";
            }
            else{
                a[++top]=x;

            }
        }

        int pop(){
            if(top<0){
                cout<<"stack underflow";
                return 0;
            }
            else{
                int x=a[top];
                top--;
                return x;
            }
        }

        int peek(){
            if(top<0){
                cout<<"stack empty";
                return 0
            }
            else{
                return a[top];
            }
            

        }


};
