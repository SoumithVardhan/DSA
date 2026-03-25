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

ListNode* solvecycledetection(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        // Step 1: Detect cycle
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                // Step 2: Find cycle start
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
}

public:
    ListNode *detectCycle(ListNode *head) {
        return solvecycledetection(head);
    }
};