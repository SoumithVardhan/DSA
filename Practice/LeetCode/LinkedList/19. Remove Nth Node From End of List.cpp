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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return NULL;
        ListNode* tempahead=head;
        while(n--){
            if(tempahead)
            tempahead=tempahead->next;
        }
        if(tempahead == NULL){
            return head->next;
        }
        ListNode* temp=head;
        while(tempahead->next!=NULL){
            temp=temp->next;
            tempahead=tempahead->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};