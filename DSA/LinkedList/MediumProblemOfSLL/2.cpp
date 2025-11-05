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
        Node* prev = NULL;
        Node* next = head->next;
        while(next != NULL) {
            head->next = prev;
            prev = head;
            head = next;
            next = head->next;
        }
        head->next = prev;
        return head;
    }
};