#include<bits/stdc++.h>
#include "Queueheader.h"
using namespace std;
struct Node *root=NULL;
void Treecreate()
{
 struct Node *p,*t;
 int x;
 struct Queue q;
 create(&q,100);
 
 printf("Eneter root value ");
 scanf("%d",&x);
 root=(struct Node *)malloc(sizeof(struct Node));
 root->data=x;
 root->lchild=root->rchild=NULL;
 Enqueue(&q,root);
 
 while(!isEmpty(q))
 {
    p=Dequeue(&q);
    printf("eneter left child of %d ",p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->lchild=t->rchild=NULL;
        p->lchild=t;
        Enqueue(&q,t);
    }
    printf("eneter right child of %d ",p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->lchild=t->rchild=NULL;
        p->rchild=t;
        Enqueue(&q,t);
    }
 }
}
void LevelOrder(struct Node *root)
{
 struct Queue q;
 create(&q,100);
 
 printf("%d ",root->data);
 Enqueue(&q,root);
 
 while(!isEmpty(q))
{
     root=Dequeue(&q);
    if(root->lchild)
    {
        printf("%d ",root->lchild->data);
        Enqueue(&q,root->lchild);
    }
    if(root->rchild)
    {
        printf("%d ",root->rchild->data);
        Enqueue(&q,root->rchild);
    }
 }
}
int count(Node *root){
    if(root){
        return count(root->lchild)+count(root->rchild)+1;
    }
    return 0;
}
int height(Node *root){
    int x=0,y=0;
 if(root==0)
 return 0;
 x=height(root->lchild);
 y=height(root->rchild);
 if(x>y)
 return x+1;
 else
 return y+1;
    
}
int main()
{
 Treecreate();
 
 LevelOrder(root); 
 cout<<"Count"<<count(root)<<endl;
 cout<<"Height"<<height(root)<<endl;
 return 0;
}