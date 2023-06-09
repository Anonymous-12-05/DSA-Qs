//https://leetcode.com/problems/palindrome-linked-list/
#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool isPalindrome(ListNode* head) {
    ListNode *q=head;
    vector<int> v;
    while(q){
        v.push_back(q->val);
        q=q->next;
    }

    int i=0,j=v.size()-1;
    while(i<=j){
        if(v[i]!=v[j]){return false;}
        else{i++;j--;}
        
    }
    return true;

}
void display(ListNode *head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }

}
int main(){
    ListNode* head = new ListNode(2);  // Create the first node with value 2
    ListNode* current = head;  // Set the current node to the head

    // Create the remaining nodes and link them
    current->next = new ListNode(3);
    current = current->next;
    current->next = new ListNode(4);
    current = current->next;
    current->next = new ListNode(5);
    current = current->next;
    current->next = new ListNode(6);
    current = current->next;
    current->next = nullptr;
    //ListNode* first=reverseList(head);
    //display(first);

}