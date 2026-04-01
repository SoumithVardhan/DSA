#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* solvemiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        ListNode* next=head;
        while(temp!=NULL){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }return prev;
    }
    void reorderList(ListNode* head) {
       ListNode* findmiddle=solvemiddle(head);
       ListNode* newhead=findmiddle->next;
       findmiddle->next=NULL;
       ListNode* newhead2=reverse(newhead);

       ListNode* temp1=head;
       ListNode* temp2=newhead2;

       while(temp1!=NULL && temp2!=NULL){
            ListNode* nexttemp1=temp1->next;
            ListNode* nexttemp2=temp2->next;

            temp1->next=temp2;
            temp2->next=nexttemp1;

            temp1=nexttemp1;
            temp2=nexttemp2;
       } 
    }
};