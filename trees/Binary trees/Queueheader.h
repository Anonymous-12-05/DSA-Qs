#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *lchild;
    int data;
    Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
    /* data */
};
void create(Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new Node*[q->size];

}
void Enqueue(Queue*q,Node * x){
    if(q->rear==q->size-1){
        cout<<"Queue is full "<<endl;
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
Node * Dequeue(Queue *q){
    Node * x=NULL;
    if(q->front==q->rear){cout<<"Empty"<<endl;}
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(Queue q){
    return q.front==q.rear;
}
