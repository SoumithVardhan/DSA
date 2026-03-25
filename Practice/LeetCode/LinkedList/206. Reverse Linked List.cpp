#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //Approach 1: Iterative
    ListNode* reverseListIterative(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

    //Approach 2: Recursive
    ListNode* reverseListRec(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverseListRec(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};