//https://leetcode.com/problems/online-stock-span/
#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
    stack<pair<int,int>> s; //1st is index and 2nd is value
    int index;
public:
    
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index +=1;
        
        while(!s.empty() && s.top().second<=price)    //Find the previous greater element
            s.pop();
        //If there is no previous greater element
        if(s.empty())
        {   s.push({index,price});      return index+1;   }
        
        int result = s.top().first;
        s.push({index,price});
        return index-result;      
    }
};