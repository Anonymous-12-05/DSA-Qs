//https://leetcode.com/problems/reverse-words-in-a-string/
#include <bits/stdc++.h>
using namespace std;
string reverseString(string &s){
	string result;
    int i=0;
    int n=s.size();
    while(i<n){
        while(i<n && s[i]==' '){
            i++;
        }
        if(i>=n){break;}
        int j=i+1;
        while(j<n && s[j]!=' '){j++;}
        string sub=s.substr(i,j-i);
        if(result.length()==0){result=sub;}
        else{
            result=sub+" "+result;
        }
        i=j+1;
    }
    return result;
}
int main(){
    string s="the sky is blue";
    // int i=0,j;
    // while(i<s.size()){
    //     while(i<s.size() && s[i]==' '){
    //         i++;
    //     }
    //     j=i+1;
    //     while(j<s.size() && s[j]!=' '){
    //         j++;
    //     }
    //     string result="";
    // //s.substr(i,j-i);
    //     result=s.substr(i,j-i) +" "+ result;
    //     cout<<result;
    // // i=s.size();
    // // int j;
    // // for(j=0;i>=0;i--,j++){
    // //     b[j]=s[i];
    // // }
    // // cout<<b;
    //     i=j+1;
    // }
    cout<<reverseString(s);
}