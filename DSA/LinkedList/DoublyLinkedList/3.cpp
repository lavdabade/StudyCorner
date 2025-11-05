#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head->next == NULL) return head; 
        Node* next = head->next;
        while(next != NULL) {
            head->next = head->prev;
            head->prev = next;
            head = next;
            next = head->next;
        }
        head->next = head->prev;
        head->prev = NULL;
        return head;
    }
};