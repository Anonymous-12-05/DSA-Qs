//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include <bits/stdc++.h> 
using namespace std;
void sortStack(stack<int> &stack)
{
    vector<int>v;
    while(!stack.empty()){
        v.push_back(stack.top());
        stack.pop();
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        stack.push(v[i]);
    }
    // Write your code here
}