//https://leetcode.com/problems/linked-list-cycle-ii/description/
#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *detectCycle(ListNode *head) {
        ListNode *temp1 = head;
        ListNode *temp2 = head;
        while(temp2!=NULL && temp2->next!=NULL)
        {
            temp1= temp1->next;
            temp2 = temp2->next->next;
            if(temp1==temp2)
            {
                temp1= head;
                while(temp1!=temp2)
                {
                    temp1= temp1->next;
                    temp2=temp2->next;
                }
                return temp1;
            }
        }
        return NULL;
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