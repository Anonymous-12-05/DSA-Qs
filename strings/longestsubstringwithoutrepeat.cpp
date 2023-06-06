#include<bits/stdc++.h>
using namespace std;
int count(string b,char a){
    int c1=0;
    for(int i =0;i<b.size();i++){
        if(b[i]==a){
            c1++;
        }
    }
    return c1;
}
int lengthOfLongestSubstring(string s) {
    vector<int> c;
    vector<string>subs;
    int i,j;
    for(i=0;i<s.size();i++){
        string a;
        for(j=i;j<s.size();j++){
            a+=s[j];
            subs.push_back(a);
        }
        // subs.push_back(a);
    }
    for(int x=0;x<subs.size();x++){
        cout<<subs[x]<<" ";
    }
    cout<<endl;
    for(int x=0;x<subs.size();x++){
        for(int y=0;y<subs[x].size();y++){
            if(count(subs[x],subs[x][y])>1){
                subs.erase(subs.begin()+x);
            }
        }
    }
    for(int x=0;x<subs.size();x++){
        c.push_back(subs[x].size());
    }
    cout<<"Only unique strings";
    for(int x=0;x<subs.size();x++){
        cout<<subs[x]<<" ";
    }
    return *max_element(c.begin(),c.end());
}
int main(){
    string s="pwwkew";
    cout<<lengthOfLongestSubstring(s)<<endl;    
}