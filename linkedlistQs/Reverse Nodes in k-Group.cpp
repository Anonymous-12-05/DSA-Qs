//https://leetcode.com/problems/reverse-nodes-in-k-group/
#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int length(ListNode *head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}

ListNode* reverseKgroup(ListNode* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    
    int len = length(head);
    
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    
    ListNode* pre = dummyHead;
    ListNode* cur;
    ListNode* nex;
    
    while(len >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        len -= k;
    }
    return dummyHead->next;
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