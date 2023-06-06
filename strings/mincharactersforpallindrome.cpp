//https://www.codingninjas.com/codestudio/problems/893000?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include<bits/stdc++.h>
using namespace std;
int minCharsforPalindrome(string str) {
	int i=0;
    int j=str.size()-1,trim=j;
    int ans=0;// Write your code here.
	while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else{
            ans++;
            i=0;
            j=--trim;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<minCharsforPalindrome(s)<<endl;    
    }
    //cout<<minCharsforPalindrome(s)<<endl;
}