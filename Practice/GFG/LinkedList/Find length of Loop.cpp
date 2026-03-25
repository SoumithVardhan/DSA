#include <iostream>
using namespace std;

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
    
Node* solvecycledetection(Node *head) {
        if(head == NULL) return NULL;
        Node* slow = head;
        Node* fast = head;
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
    int lengthOfLoop(Node *head) {
        Node* loopstart=solvecycledetection(head);
        if(loopstart==NULL)return 0;
        Node* temp=loopstart->next;
        int cnt=1;
        while(temp!=loopstart){
            temp=temp->next;
            cnt++;
        }
        return cnt;
        
    }
};