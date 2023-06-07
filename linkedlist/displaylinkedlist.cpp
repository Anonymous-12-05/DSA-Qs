#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    /* data */
}*first;
void create(int A[],int n){
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

void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
void recDisplay( Node *p){
    if(p!=NULL){
        cout<<p->data<<" ";
        recDisplay(p->next);
    }
}
void reverse(Node *p){
    if(p!=NULL){
        // cout<<p->data<<" ";
        reverse(p->next);
        cout<<p->data<<" ";
    }
}
int count(Node *p){
    if(p!=NULL){
        return count(p->next)+1;
    }
    return 0;
}
int sum(Node *p){
    if(p!=NULL){
        return sum(p->next)+p->data;
    }
    return 0;
}
int maximum(Node *p){
    int maxim=INT_MIN;
    while(p!=NULL){
        if(maxim<p->data){
            maxim=p->data;
            
        }
        p=p->next;
    }
    return maxim;
}
int recursivemax(Node *p){
    if(p==NULL){
        return INT_MIN;
    }
    else{
        int x=0;
        x=recursivemax(p->next);
        if(x>p->data){
            return x;
        }
        else{
            return p->data;
        }
    }
}
Node* linsearch(Node *p,int x){
    while(p!=NULL){
        if(p->data==x){
            return (p);
        }
        p=p->next;
    }
    return NULL;
}
Node* reclinsearch(Node *p,int x){
    if(p==NULL){
    return NULL;
    }
    if(x==p->data){
        return p;
    }
    return reclinsearch(p->next,x);
}
Node* betterSearch(Node *p,int x){
    Node *q=NULL;
    if(p==NULL){
        return NULL;
    }
    while(p!=NULL){
        if(x==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
void Insert(int pos,int x,Node* p){
    if(pos<0 || pos>count(p)){return;}
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
void insertSortedLL(int x,Node *p){
    Node *t,*tail=NULL;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(p==NULL){
        first=t;
    }
    else{
        while(p && p->data<x){
            tail=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=tail->next;
            tail->next=t;
        }
    }
    



}
int deletenode(int x,Node *p){
    Node *q;
    int n=-1,i;
    if(x<1 || x>count(p)){return -1;}
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
    int A[5]={3,5,7,10,15};
    create(A,5);
    display(first);
    cout<<endl;
    recDisplay(first);
    cout<<endl;
    reverse(first);
    cout<<endl;
    cout<<count(first)<<endl;
    cout<<sum(first)<<endl;
    cout<<maximum(first)<<endl;
    cout<<recursivemax(first)<<endl;
    cout<<linsearch(first,7)<<endl;
    cout<<reclinsearch(first,7)<<endl;
    // cout<<betterSearch(first,10)<<endl;
    // Insert(0,14,first);
    insertSortedLL(1,first);
    display(first);
    cout<<endl;
    cout<<deletenode(4,first)<<endl;
    display(first);
}

