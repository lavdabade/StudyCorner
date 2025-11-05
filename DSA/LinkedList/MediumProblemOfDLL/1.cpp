#include<iostream>

using namespace std;

class Node {
  public:
     int data;
     Node *prev;
     Node *next;
     Node() {
         this->data = 0;
         this->prev = NULL;
         this->next = NULL;
     }
     Node(int data) {
         this->data = data;
         this->prev = NULL;
         this->next = NULL;
     }
     Node (int data, Node *next, Node *prev) {
         this->data = data;
         this->prev = prev;
         this->next = next;
     }
};

class Solution {
    Node * deleteAllOccurrences(Node* head, int x) {
    // Write your code here
        while(head!= NULL && head->data==x) head = head->next;
        Node* temp = head;
        while(temp != NULL) {
            if(temp->data == x) {
                temp->prev->next = temp->next;
                if(temp->next) temp->next->prev = temp->prev;
            }
            temp = temp->next;
        }
        return head;
    }
};