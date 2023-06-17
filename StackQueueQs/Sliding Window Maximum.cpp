//https://leetcode.com/problems/sliding-window-maximum/
#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> sums;
    for(int i=0;i<nums.size();i++){
        int maxim;
        vector<int>smaxi;
        if((i+k)>nums.size()){break;}
        for(int j=i;j<i+k;j++){
            //vector<int>smaxi;
            smaxi.push_back(nums[j]);

        }
        sums.push_back(*max_element(smaxi.begin(),smaxi.end()));
    }
    return sums;
   
}
vector<int>maxSlidingWindow(vector<int>&nums,int k) {
    deque<int>dq;
    vector<int>ans;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() == i - k){ dq.pop_front();}

        while (!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);
        if (i >= k - 1){ ans.push_back(nums[dq.front()]);}
    }
    return ans;
} 
int main(){
    vector<int> nums={1},sums=maxSlidingWindow(nums,1);
    for(int i=0;i<sums.size();i++){
        cout<<sums[i]<<" ";
    }

}