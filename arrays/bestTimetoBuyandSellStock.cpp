#include<bits/stdc++.h>
#include<typeinfo>
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
using namespace std;
int maxProfit(vector<int>& prices) {
        // int minimum=INT_MAX;
        // int minindex=-1;
        // for(int i=0;i<prices.size();i++){
        //     if(prices[i]<minimum){
        //         minimum=prices[i];
        //         minindex=i;
        //     }
        // }
        // if (minindex==prices.size()-1){
        //     int min2=minindex;
        //     int min2no=INT_MAX;
        //     for(int i=0;i<prices.size() && i!=min2;i++){
        //     if(prices[i]<min2no){
        //         min2no=prices[i];
        //         minindex=i;
        //     }
        //     minimum=min2no;
        //     //minindex=min2;
        // } 
        // }
        // //cout<<minimum<<" "<<minindex<<endl;
        // int maximum=-1;
        // for(int i=minindex;i<prices.size();i++){
        //     if(prices[i]>maximum){
        //         maximum=prices[i];
        //     }
        // }
        // //cout<<maximum<<endl;
        // return maximum-minimum;
        // vector<int> diff;
        // for(int i=0;i<prices.size();i++){
        //     for(int j=i+1;j<prices.size();j++){
        //         int difference=prices[i]-prices[j];
        //         diff.push_back(difference);
        //     }
        // }
        // //cout<<(*min_element(diff.begin(),diff.end()))*-1<<endl;
        // if((*min_element(diff.begin(),diff.end()))*-1<0){
        //     return 0;
        // } 
        // else{
        //     return (*min_element(diff.begin(),diff.end()))*-1 ;
        // }
        int left=0,right=1;
        int maxprofit=0;
        while(right<prices.size()){
            //profit?
            if(prices[left]<prices[right]){
                int profit=prices[right]-prices[left];
                maxprofit=max(maxprofit,profit);
            }
            else{
                left=right;
            }
            right+=1;
        }
        return maxprofit;

        

    }
int main(){
    
    vector<int> prices={2,4,1};
    cout<<maxProfit(prices)<<endl;
}