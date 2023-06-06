//https://leetcode.com/problems/repeated-string-match/description/
#include<bits/stdc++.h>
using namespace std;
int repeatedStringMatch(string a, string b) {
    // b=prefix+n*a+suffix    n+2
    // b=prefix+n*a           n+1
    // b=n*a+suffix           n+1
    // b=n*a                  n
    //npos=-1
    int n=b.size()/a.size();
    int cnt=n;
    string na="";
    while(cnt--){
        na+=a;
    }
    if(na.find(b)!=string::npos){
        return n;
    }
    na+=a;
    if(na.find(b)!=string::npos){
        return n+1;
    }
    na+=a;
    if(na.find(b)!=string::npos){
        return n+2;
    }
    return -1;

}
int main(){
    string a ="abcd", b = "cdabcdab";
    cout<<repeatedStringMatch(a,b);
}