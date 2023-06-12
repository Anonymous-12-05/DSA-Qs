#include <bits/stdc++.h>
using namespace std;
struct Matrix{
    int *A;
    int n;
};
void Set(Matrix *m,int i,int j,int x){
    if(i>=j){
        m->A[(i*(i-1)/2)+(j-1)]=x;//RMO
    }
}
void SetCMO(Matrix *m,int i,int j,int x){
    if(i>=j){
        m->A[(m->n*(j-1)+(j-2)*(j-1)/2+i-j)]=x;//RMO
    }
}
int Get(Matrix m,int i,int j){
    if(i>=j){return m.A[(i*(i-1)/2)+(j-1)];}
    else{
    return 0;
    }
}
int GetCMO(Matrix m,int i,int j){
    if(i>=j){return m.A[(m.n*(j-1)+(j-2)*(j-1)/2+i-j)];}
    else{
    return 0;
    }
}
void display(Matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        {
            for(j=1;j<=m.n;j++){
                if(i>=j){
                    cout<<m.A[(i*(i-1)/2)+(j-1)]<<" ";
                }
                else{
                    cout<<0<<" ";
                }
            }
            cout<<endl;
        }
    }
}
void displayCMO(Matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        {
            for(j=1;j<=m.n;j++){
                if(i>=j){
                    cout<<m.A[(m.n*(j-1)+(j-2)*(j-1)/2+i-j)]<<" ";
                }
                else{
                    cout<<0<<" ";
                }
            }
            cout<<endl;
        }
    }
}
int main(){
    struct Matrix m;
    cin>>m.n;
    int i,j;
    m.A=new int[(m.n*(m.n+1))/2];
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            int x;
            cin>>x;
            SetCMO(&m,i,j,x);
        }
    }
    cout<<endl;
    // Set(&m,4,4,12);Set(&m,1,1,5);Set(&m,2,2,8);Set(&m,3,3,9);
    //Set(&m,3,3,12);
    displayCMO(m);
    
}
// #include <stdio.h>
// struct Matrix
// {
//  int A[10];
//  int n;
// };
// void Set(struct Matrix *m,int i,int j,int x)
// {
//  if(i==j)
//  m->A[i-1]=x;
 
// }
// int Get(struct Matrix m,int i,int j)
// {
//  if(i==j)
//  return m.A[i-1];
//  else
//  return 0;
// }
// void Display(struct Matrix m)
// {
//  int i,j;
//  for(i=0;i<m.n;i++)
//  {
//  for(j=0;j<m.n;j++)
//  {
//  if(i==j)
//  printf("%d ",m.A[i]);
//  else
//  printf("0 ");
//  }
//  printf("\n");
//  }
// }
// int main()
// {
//  struct Matrix m;
//  m.n=4;
 
//  Set(&m,1,1,5);Set(&m,2,2,8);Set(&m,3,3,9);Set(&m,
// 4,4,12);
//  printf("%d \n",Get(m,2,2));
//  Display(m);
//  return 0;
// }