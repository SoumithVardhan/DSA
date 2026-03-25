#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool solve(ListNode* head,ListNode* slow,ListNode* fast){
    while(fast!=NULL){
        if(fast==slow)return true;
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL)
        fast=fast->next;
    }
    return fast==slow;
}
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)return false;
        ListNode* slow=head;
        ListNode* fast=head->next;
        return solve(head,slow,fast);
    }
};