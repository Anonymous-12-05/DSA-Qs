#include <bits/stdc++.h>
using namespace std;
class LowerTriangle{
    private:
        int n;
        int *A;
    public:
    LowerTriangle(){
            n=2;
            A=new int[2];
        }
    LowerTriangle(int n){
            this->n=n;//this n means n in private
            A=new int[n];
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~LowerTriangle(){delete[] A;}
};
void LowerTriangle::Set(int i,int j,int x){
    if(i==j){
        A[i-1]=x;
    }
}
int LowerTriangle::Get(int i,int j){
    if(i==j){
        return A[i-1];
    }
    return 0;
}
void LowerTriangle::Display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<A[i]<<" ";
            }
            else{
                cout<<0<<" ";
            
            }
        }
        cout<<endl;
    }
}
int main(){
    LowerTriangle d(4);
    d.Set(1,1,5);
    d.Set(2,2,8);
    d.Set(3,3,9);
    d.Set(4,4,12);
    d.Display();
}