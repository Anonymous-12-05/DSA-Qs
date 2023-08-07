#include<bits/stdc++.h>
using namespace std;
#define SIZE 10

int Hash(int key){
    return key%10;
}

int probe(int H[],int key){
    int index=Hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0){
        i++;
    }
    return (index+i)%SIZE;
}

void Insert(int H[],int key){
    int index=Hash(key);

    if(H[index]!=0){
        index=probe(H,key);
    }
    H[index]=key;
}

int Search(int H[],int key){
    int index=Hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key){
        i++;
    }
    return (index+i)%SIZE;

}

int main(){
    int HT[10]={0};
    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);
    for(int i=0;i<10;i++){
        cout<<HT[i]<<" ";
    }
    cout<<Search(HT,12);


}