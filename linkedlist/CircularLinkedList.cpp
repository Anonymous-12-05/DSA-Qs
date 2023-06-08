#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
}*head;

void create(int A[],int n){
    int i;
    Node *t,*last;
    head = new Node;
    head->data=A[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next; 
        last->next=t;
        last=t;
    }

}
void display(Node *p){
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}
int length(Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}
void insert(Node *p,int index,int x){
    Node *t;
    int i;
    if(index<0 || index>length(p)){return;}
    if(index==0){
        t=new Node;
        t->data=x;
        if(head==NULL){
            head=t;
            head->next=head;
        }
        else{
            while(p->next!=head){
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t; //if you want to make new element as head
        }
    }
    else{
        t=new Node;
        for(i=0;i<index-1;i++){p=p->next;}
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
}
void recdisplay(Node *p){
    static  int flag=0;
    if(flag==0 || p!=head){
        flag=1;
        cout<<p->data<<" ";
        recdisplay(p->next);
    }
    flag=0;
    cout<<endl;

}
int DeleteCll(Node *p,int pos){
    if(pos<1 || pos>length(head)){
        return -1;
    }
    Node *q;
    int x;
    if(pos==1){
        while(p->next!=head){
            p=p->next;
        }
        x=head->data;
        if(p==head){
            delete head;
            head=NULL;
        }
        else{
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }
    else{
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;

    }
    return x;
}
int main(){
    int A[]={2,3,4,5,6};
    create(A,5);
    recdisplay(head);
    cout<<DeleteCll(head,1)<<endl;
    recdisplay(head);
}