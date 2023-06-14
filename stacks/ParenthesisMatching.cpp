#include<bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    Node *next;
}*top=NULL;
void push(char x){
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
char pop(){
    Node *t;
    char x='!';
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
int isbalanced(string exp){
    int i;
    for(i=0;exp[i]!='\0';i++ ){
        if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            if(top==NULL){
                return 0;
            }
            pop();
        }
    }
    if(top==NULL){
        return 1;
    }
    return 0;
}
int main(){
    string exp="((a+b)*(c-d))";
    cout<<isbalanced(exp);
}