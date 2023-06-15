#include <bits/stdc++.h>
using namespace std;
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
    /* data */
};
void create(Queue *q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=new int[q->size];

}
void Enqueue(Queue*q,int x){
    if(((q->rear+1)%q->size)==q->front){
        cout<<"Queue is full "<<endl;
    }
    else{
        q->rear=((q->rear+1)%q->size);
        q->Q[q->rear]=x;
    }
}
int Dequeue(Queue *q){
    int x=-1;
    if(q->front==q->rear){cout<<"Empty"<<endl;}
    else{
        q->front=((q->front+1)%q->size);
        x=q->Q[q->front];
    }
    return x;
}
void Display(Queue q){
    int i=q.front+1;
    do{
        cout<<q.Q[i]<<" ";
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    cout<<endl;
}
int main(){
    Queue q;
    create(&q,5);
    Enqueue(&q,10);
    Enqueue(&q,20);
    Enqueue(&q,30);
    Enqueue(&q,40);
    Display(q);
    cout<<Dequeue(&q)<<endl;
    Display(q);
}