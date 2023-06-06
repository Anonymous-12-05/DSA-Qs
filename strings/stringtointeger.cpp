//https://leetcode.com/problems/string-to-integer-atoi/
#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
    int len=s.size();
    int i=0,sign=1;
    long long out=0;
    while(i<len && s[i]==' '){i++;}
    if(i==len){
        return 0;
    }        
    if(s[i]=='-'){
        sign =0;
        i++;
    }
    else if(s[i]=='+'){
        sign =1;
        i++;
    }
    while(s[i]>='0' &&  s[i]<='9'){
        out=out*10;
        if(out<=INT_MIN || out>=INT_MAX){
            break;
        }
        out+=(s[i]-'0');
        i++;

    }
    if(sign==0){
        out= -1*out;
    }
    if(out<=INT_MIN){
        return INT_MIN;
    }
    if(out>=INT_MAX){
        return INT_MAX;
    }
    return out;
        
    
}
int main(){
    string s="   321";
    cout<<myAtoi(s);
} 