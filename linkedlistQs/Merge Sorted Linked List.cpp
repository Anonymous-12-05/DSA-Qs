//https://leetcode.com/problems/merge-two-sorted-lists/
#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){return list2;}
        if(list2==NULL){return list1;}
        ListNode *third,*last;
        if(list1->val<list2->val){
            third=last=list1;
            list1=list1->next;
            last->next=NULL;
        }
        else{
            third=last=list2;
            list2=list2->next;
            last->next=NULL;
        }
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                last->next=list1;
                last=list1;
                list1=list1->next;
                last->next=NULL;
            }
            else{
                last->next=list2;
                last=list2;
                list2=list2->next;
                last->next=NULL;
            }

        }
        if(list1){
            last->next=list1;
        }
        else{
            last->next=list2;
        }
        return third;
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
    ListNode* head2 = new ListNode(20);  // Create the first node with value 2
    ListNode* current2 = head2;  // Set the current node to the head

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
    ListNode* first=mergeTwoLists(head,head2);
    display(first);

}