//https://leetcode.com/problems/linked-list-cycle/
#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool hasCycle(ListNode *head) {
        // ListNode *temp=head;
        // if(temp==NULL){return false;}
        // while(temp->next!=NULL){
        //     if(temp==head){
        //         return true;
        //     }
        //     temp=temp->next;
        // } 
        // return false;     
        if(head==NULL)
        {
            return false;
        }
        ListNode *temp1= head;
        ListNode *temp2=head->next;
        while(temp1!=temp2)
        {
            if(temp2==NULL or temp2->next==NULL)
            {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next->next;
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
    // ListNode* first=reverseList(head);
    // display(first);

}