#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        if(x == 1) {
            head = head->next;
            if(head) head->prev = NULL;
            return head;
        }
        Node* temp = head;
        while(x > 1) {
            temp = temp->next;
            x--;
        }
        temp->prev->next = temp->next;
        if(temp->next) temp->next->prev = temp->prev;
        return head;
    }
};