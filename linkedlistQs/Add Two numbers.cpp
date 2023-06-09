//https://leetcode.com/problems/add-two-numbers/
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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // int carry=0;
    // ListNode *answer=new ListNode;
    // ListNode* first=l1;
    // ListNode * second=l2;
    // ListNode *p=first,*q=second;
    // while(p && q){
    //     answer->val=p->val+q->val+carry;
    //     if(answer->val>=10){
    //         answer->val=answer->val-10;
    //         carry=1;
    //     }
    //     p=p->next;
    //     q=q->next;
    //     answer=answer->next;
    // }
    // if(p){
    //     answer=p;
    // }
    // if(q){answer=q;}
    // return answer;
    ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 

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
    current->next = new ListNode(4);
    current = current->next;
    current->next = new ListNode(3);
    // current = current->next;
    // current->next = new ListNode(5);
    // current = current->next;
    // current->next = new ListNode(6);
    // current = current->next;
    current->next = nullptr;
    ListNode* head2 = new ListNode(5);  // Create the first node with value 2
    ListNode* current2 = head2;  // Set the current node to the head

    // Create the remaining nodes and link them
    current2->next = new ListNode(6);
    current2 = current2->next;
    current2->next = new ListNode(4);
    // current2 = current2->next;
    // current2->next = new ListNode(50);
    // current2 = current2->next;
    // current2->next = new ListNode(60);
    // current2 = current2->next;
    current2->next = nullptr;
    ListNode* first=addTwoNumbers(head,head2);
    display(first);

}