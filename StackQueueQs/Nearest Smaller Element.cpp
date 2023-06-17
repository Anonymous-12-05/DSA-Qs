//https://www.interviewbit.com/problems/nearest-smaller-element/
#include<bits/stdc++.h>
using namespace std;
vector<int>prevSmaller(vector<int> &A) {

    vector<int> result;

    stack<int> st;

    st.push(-1);



    for(int a : A)

    {

        while(st.top() >= a) st.pop();


        result.push_back(st.top());


        st.push(a);

    }

    return result;

}

int main(){
    vector<int> A={4, 5, 2, 10, 8};
    vector<int> soln=prevSmaller(A);
    for(int i=0;i<soln.size();i++){
        cout<<soln[i]<<" ";
    }
}