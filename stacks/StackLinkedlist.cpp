#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
}*top=NULL;
void push(int x){
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
int pop(){
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
void display(){
    Node *p;
    p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    display();
}