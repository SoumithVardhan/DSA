#include <iostream>
using namespace std;

//Approach
/*
You should not reverse the complete LinkedList
If So after reversing newhead will be at the end it is perfect but the head node's next will point to NULL

Eg: 1->2->2->1
you should reverse from the middle
1->2 and then 2<-1 after reversing now you will compare head & newhead values
1==1 && 2==2 now you will return true
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = reverse(slow->next);
        ListNode* first = head;
        while(second != NULL){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};