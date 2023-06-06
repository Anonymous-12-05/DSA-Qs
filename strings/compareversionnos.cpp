
//https://leetcode.com/problems/compare-version-numbers/
#include<bits/stdc++.h>
using namespace std;
int compareVersion(string version1, string version2) {
    int i=0,j=0,n1,n2;
    while(i<version1.size()||j<version2.size()){
        n1=0;n2=0;
        while(i<version1.size() && version1[i]!='.'){
            n1=n1*10+(version1[i]-'0');
            i++;
        }
        while(j<version2.size() && version2[j]!='.'){
            n2=n2*10+(version2[j]-'0');
            j++;
        }
        if(n1<n2){
            return -1;
        }
        else if(n1>n2){return 1;}
        i++;
        j++;

    }
    return 0;
}
int main(){
    string v1="1.0.1",v2="1";
    cout<<compareVersion(v1,v2)<<endl;
}