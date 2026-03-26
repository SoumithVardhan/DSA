#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=temp2){
            if(temp1==temp2)return temp1;
            if(temp1==NULL){
                temp1=headB;
            }
            else temp1=temp1->next;
            if(temp2==NULL){
                temp2=headA;
            }
            else temp2=temp2->next;
        }return temp1;
    }

    ListNode *getIntersectionNodeApproach2(ListNode *headA, ListNode *headB) {
        int n=0,m=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL){
            n++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            m++;
            temp2=temp2->next;
        }
        int ans=abs(n-m);
        if(n>m){
            while(ans--){
                headA=headA->next;
            }
        }
        else{
            while(ans--){
                headB=headB->next;
            }
        }
        while(headA != NULL && headB != NULL){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }return NULL;
    }
};


