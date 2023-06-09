//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // if(n<0 && n>length(head)){return NULL;}
    // ListNode *p,*q;
    // p=head;
    // for(int i=1;i<(length(head)-n);i++){
    //     p=p->next;
    // }
    // q=p;
    // p=p->next;
    // if(p->next){q->next=p->next;}
    // else{q->next=NULL;}
    // delete p;
    // return head;
    ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;

}
        
void display(ListNode *head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }

}
int main(){
    ListNode* head = new ListNode(1);  // Create the first node with value 2
    ListNode* current = head;  // Set the current node to the head

    // Create the remaining nodes and link them
    current->next = new ListNode(2);
    current = current->next;
    current->next = new ListNode(3);
    current = current->next;
    current->next = new ListNode(4);
    current = current->next;
    current->next = new ListNode(5);
    current = current->next;
    current->next = nullptr;
    ListNode* head2 = new ListNode(20);  // Create the first node with value 2
    ListNode* current2 = head2;  // Set the current node to the head
    display(head);
    cout<<endl;
    // Create the remaining nodes and link them
    current2->next = new ListNode(30);
    current2 = current2->next;
    current2->next = new ListNode(40);
    current2 = current2->next;
    current2->next = new ListNode(50);
    current2 = current2->next;
    current2->next = new ListNode(60);
    current2 = current2->next;
    current2->next = nullptr;
    ListNode* first=removeNthFromEnd(head,2);
    display(first);

}