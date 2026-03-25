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
    ListNode* solve(ListNode* head){
        if(head==NULL || head->next==NULL)return head;
        ListNode* startodd=head;
        ListNode* starteven=head->next;
        ListNode* head2=starteven;
        while(starteven!=NULL && starteven->next!=NULL){
            startodd->next=starteven->next;
            startodd=startodd->next;

            starteven->next=startodd->next;
            starteven=starteven->next;
        }
        startodd->next=head2;
        return head;
    }
    ListNode* oddEvenList(ListNode* head) {
        return solve(head);
    }
};