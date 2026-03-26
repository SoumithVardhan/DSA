#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* segregate(Node* head) {
        Node* first=new Node(-1);
        Node* second=new Node(-1);
        Node* third=new Node(-1);

        Node* firststart=first;
        Node* secondstart=second;
        Node* thirdstart=third;
        
        while(head!=NULL){
            if(head->data==0){
                first->next=head;
                head=head->next;
                first=first->next;
                first->next=NULL;
            }
            else if(head->data==1){
                second->next=head;
                head=head->next;
                second=second->next;
                second->next=NULL;
            }
            else if(head->data==2){
                third->next=head;
                head=head->next;
                third=third->next;
                third->next=NULL;
            }
        }
        // terminate all three chains first
        first->next = NULL;
        second->next = NULL;
        third->next = NULL;
    
        first->next  = secondstart->next ? secondstart->next : thirdstart->next;
        second->next = thirdstart->next;

        return firststart->next ? firststart->next 
             : (secondstart->next ? secondstart->next 
             : thirdstart->next);
    }
};