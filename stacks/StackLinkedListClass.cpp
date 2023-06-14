#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class Stack{
    private:    
        Node *top;
    public:
        Stack(){top=NULL;}
        void push(int x);
        int pop();
        void display();

};
void Stack::push(int x){
    struct Node*t;
    t=new Node;
    if(t==NULL){
        cout<<"stack full"<<endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
int Stack:: pop(){
    Node *t;
    int x=-1;
    if(top==NULL){cout<<"Empty"<<endl;}
    else{
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}
void Stack::display(){
    Node *p;
    p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.display();
    
}