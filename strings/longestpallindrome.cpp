//https://leetcode.com/problems/longest-palindromic-substring/
#include<bits/stdc++.h>
using namespace std;
bool pallindrome(string s){
    int i,j;
    for(i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j]){
            return false;
        }
    }
    return true;
}
string longestPalindrome(string s) {
    vector<string>words;

    int i,j;
    for(i=0;i<s.size();i++){
        string word;
        for(j=i;j<s.size();j++){
            word+=s[j];
            words.push_back(word);
        }
    }
    int large=0;
    string largest="";
    for(int x=0;x<words.size();x++){
        //cout<<words[x]<<" ";
        if(words[x].size()>large && pallindrome(words[x])){
            large=words[x].size();
            largest=words[x];
        }
    }
    return largest;

}
string longPalindrome(string s) {
        if(s.length()==1){return s;}
        int max_len=1;
        int n=s.size();
        int st=0,end=0;
        //Odd length
        for(int i=0;i<n;++i){
            int l=i,r=i;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--;r++;
                }else{break;}
            }
            int len=r-l-1;
            if(len>max_len){
                max_len=len;
                st=l+1;
                end=r-1;
            }
        }
        //Even Length
        for(int i=0;i<n;i++){
            int l=i,r=i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--;r++;
                }else{break;}
            }
            int len=r-l-1;
            if(len>max_len){
                max_len=len;
                st=l+1;
                end=r-1;
            }
        }
        return s.substr(st,max_len);

    }
int main(){
    string s="babad";
    cout<<longPalindrome(s)<<" "<<s.size();
}