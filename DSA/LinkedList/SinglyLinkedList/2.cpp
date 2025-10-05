#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* newNode = new Node(x);
        if(!head) return newNode;
        Node* node = head;
        while(node->next) node = node->next;
        node->next = newNode;
        return head;
    }
};