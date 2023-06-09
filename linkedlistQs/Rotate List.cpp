//https://leetcode.com/problems/rotate-list/description/
#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void rotate(int arr[], int n)
{
    int dup[n];
    int x=arr[n-1];
    dup[0]=x;
    for(int i=1;i<n;i++){
        dup[i]=arr[i-1];
    }
    for(int i=0;i<n;i++){
        arr[i]=dup[i];
    }
    
        
}
// void create(int A[],int n){
//     int i;
//     struct Node *t,*last;
//     first=new Node;
//     first->data=A[0];
//     first->next=NULL;
//     last=first;
//     for(i=1;i<n;i++){
//         t=new Node;
//         t->data=A[i];
//         t->next=NULL;
//         last->next=t;
//         last=t;
//     }
// }
int length(ListNode *head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
ListNode* rotateRight(ListNode* head, int k) {
   if(head == NULL||head->next == NULL||k == 0) return head;
    //calculating length
    ListNode* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    //link last node to first node
    temp->next = head;
    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    //breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
        
    return head;
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