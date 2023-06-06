//https://leetcode.com/problems/valid-anagram/
#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
        int arr[26]={0};
        int i;
        // if(s.size()!=t.size()){
        //     return false;
        // }
        for(i=0;i<s.size();i++){
            arr[s[i]-97]++;
        }
        for(i=0;i<t.size();i++){
            arr[t[i]-97]--;
            // if(arr[t[i]-97]<0){
            //     return false;
            // }
        }
        for(int x=0;x<27;x++){
            if(arr[x]!=0){
                return false;
            }
        }
        return true;

    }
int main(){
    string s="car",t="rat";
    cout<<isAnagram(s,t)<<endl;
}