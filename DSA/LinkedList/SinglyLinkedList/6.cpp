#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        while(head) {
            if(head->data == key) return true;
            head = head->next;
        }
        return false;
    }
};
