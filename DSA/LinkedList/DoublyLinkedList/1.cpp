#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node* newNode = new Node(x);
        Node* temp = head;
        while(p > 0) {
            temp = temp->next;
            p--;
        }
        newNode->next = temp->next;
        if(temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }
};