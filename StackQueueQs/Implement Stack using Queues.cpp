//https://leetcode.com/problems/implement-stack-using-queues/
#include<bits/stdc++.h>
using namespace std;
// class MyStack {
//     private:
//         queue<int> q1;
//         queue<int> q2;
// public:
//     MyStack() {

//     }
    
//     void push(int x) {
//         q2.push(x);
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1,q2);
//     }
    
//     int pop() {
//         int x=q1.front();
//         q1.pop();
//         return x;
        
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         if(q1.empty() && q2.empty()){
//             return true;
//         }
//         return false;
//     }
// };
class MyStack {
    private:
        queue<int> q1;
        //queue<int> q2;
public:
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
        int size1=q1.size();
        for(int i=0;i<size1-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        //q1.pop();
        int x=q1.front();
        q1.pop();
         return x;
        
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */