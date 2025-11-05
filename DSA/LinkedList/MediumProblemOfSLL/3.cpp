#include<iostream>

using namespace std;

class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};


class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        if(head==NULL || head->next==NULL) return head;
        Node* headPtr = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return headPtr;
    }
};