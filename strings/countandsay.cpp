//https://leetcode.com/problems/count-and-say/
#include<bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
    if(n==1){
        return "1";
    }
    if(n==2){
        return "11";
    }
    string a="11";
    for(int i=3;i<=n;i++){
        string t="";
        a=a+"&";
        int c=1;
        for(int j=1;j<a.length();j++){
            if(a[j]!=a[j-1]){
                t+=to_string(c);
                t+=a[j-1];
                c=1;

            }
            else{c++;}
        }

        a=t;
    }
    return a;
    
    

}
int main(){
    cout<<countAndSay(4)<<endl;
}