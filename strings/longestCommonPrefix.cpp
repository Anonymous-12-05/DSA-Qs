//https://leetcode.com/problems/longest-common-prefix/
#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    string minim=*min_element(strs.begin(),strs.end());
    int count=0;
    int len=minim.size();
    for(int i=0;i<len;i++){
        for(int j=0;j<strs.size();j++){
            if(strs[j][i]!=minim[i]){
                return minim.substr(0,count);
            }
        }
        count++;
    }
    return minim.substr(0,count);
}
int main(){
    vector<string> strs={"dog","racecar","car"};
    cout<<longestCommonPrefix(strs);
}