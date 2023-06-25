#include <bits/stdc++.h>
#define I 32767
using namespace std;
int edges[3][9]={{1,1,2,2,3,4,4,5,5},
                 {2,6,3,7,4,5,7,6,7},
                 {25,5,12,10,8,16,14,20,18}};
int sett[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int included[9]={0};
int t[2][6];

void myUnion(int u,int v){
    if(sett[u]<sett[v]){
        sett[u]+=sett[v];
        sett[v]=u;
    }
    else{
        sett[v]+=sett[u];
        sett[u]=v;
    }
}
int find(int u){
    int x=u,v=0;
    while(sett[x]>0){
        x=sett[x];
    }
    while(u!=x){
        v=sett[u];
        sett[u]=x;
        u=v;
    }
    return x;
}
int main(){
    int i=0,j,k,u,v,min=I,n=7,e=9;
    while(i<n-1){
        min=I;
        for(j=0;j<e;j++){
            if(included[j]==0 && edges[2][j]<min){
                min=edges[2][j];
                u=edges[0][j];
                v=edges[1][j];
                k=j;

            }
        }
        if(find(u)!=find(v)){
            t[0][i]=u;t[1][i]=v;
            myUnion(find(u),find(v));
            i++;
        }
        included[k]=1;

    }
    for(i=0;i<n-1;i++){
        cout<<'('<<t[0][i]<<","<<t[1][i]<<')'<<endl;
    }
}