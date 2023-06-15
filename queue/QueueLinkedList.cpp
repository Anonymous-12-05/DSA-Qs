#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    /* data */
}*front=NULL,*rear=NULL;

void enqueue(int x){
    Node *t;
    t=new Node;
    if(t==NULL){cout<<"Queue full";}
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}
int dequeue(){
    int x=-1;
    Node *t;
    if(front==NULL){
        cout<<"Queue empty";
    }
    else{
        x=front->data;
        t=front;
        front=front->next;
        delete(t);
    }
    return x;
}
void display(){
    Node *p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
}