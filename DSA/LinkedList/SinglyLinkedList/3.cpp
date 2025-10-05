#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // code here
        if(x==1) return head->next;
        Node* node = head;
        --x;
        while(--x) {
            node = node->next;
        }
        node->next = node->next->next;
        return head;
    }
};