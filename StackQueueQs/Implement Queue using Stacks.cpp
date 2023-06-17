//https://leetcode.com/problems/implement-queue-using-stacks/
#include<bits/stdc++.h>
using namespace std;
class MyQueue {
    private:
        stack<int> input,output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int x=-1;
        if(!output.empty()){
            x=output.top();
            output.pop();
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            x=output.top();
            output.pop();
        }
        return x;
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        if(input.empty() && output.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};