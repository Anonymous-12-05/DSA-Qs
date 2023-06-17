//https://leetcode.com/problems/min-stack/
#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    vector<int> v;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        int x=-1;
        for(int i=v.size()-1;i>=0;i--){
            x= v[i];
            break;
        }
        return x;
        
    }
    
    int getMin() {
        return(*min_element(v.begin(),v.end()));
    }
};