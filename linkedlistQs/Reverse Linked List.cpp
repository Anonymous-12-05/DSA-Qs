//https://leetcode.com/problems/reverse-linked-list/
#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head) {
    ListNode *p=head,*q=NULL,*r=NULL ;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }       
    return q;
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
    ListNode* first=reverseList(head);
    display(first);

}