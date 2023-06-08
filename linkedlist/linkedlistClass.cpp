#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node *first;
    public:
        LinkedList(){first=NULL;}//Constructor
        LinkedList(int A[],int n);
        ~LinkedList();//Destructor

        void Display();
        void Insert(int index,int x);
        int Delete(int index);
        int Length();
};
LinkedList::LinkedList(int A[],int n){
    int i;
    struct Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
LinkedList::~LinkedList(){
    Node *p=first;
    while (first)
    {
        first=first->next;
        delete p;
        p=first;
        /* code */
    }
    
}
void LinkedList::Display(){
    Node *p=first;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int LinkedList::Length(){
    Node *p=first;
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
void LinkedList::Insert(int pos,int x){
    Node *p=first;
    if(pos<0 || pos>Length()){return;}
    Node *t;
    t=new Node;
    t->data=x;
    if(pos==0){
        
        t->next=first;
        first=t;

    }
    else if(pos>0){
        for(int i=0;i<pos-1 && p;i++){
            p=p->next;
        }
        
            t->next=p->next;
            p->next=t;
        
    }
} 
int LinkedList::Delete(int x){
    Node *p=first;
    Node *q;
    int n=-1,i;
    if(x<1 || x>Length()){return -1;}
    if(x==1){
        q=first;
        n=first->data;
        first=first->next;
        //n=a->data;
        delete q;
        return x;
    }
    else{
        // q=NULL;
        for(i=0;i<x-1 && p;i++){
            q=p;
            p=p->next;
        }
        if(p){
        q->next=p->next;
        n=p->data;
        delete p;
        return n;
        }
    }
     return n;

}

int main(){
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);
    l.Display();
}