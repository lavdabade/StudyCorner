#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    Node* reverseList(Node* node) {
        if(node==NULL || node->next==NULL) return node;
        Node* head = reverseList(node->next);
        node->next->next = node;
        node->next = NULL;
        return head;
    }
    
  public:
    Node* addOne(Node* head) {
        // Your Code here
        head = reverseList(head);
        int dummy = 1;
        Node* headTemp = head;
        while(headTemp!=NULL && dummy==1) {
            int curr = headTemp->data + 1;
            if(curr<=9) dummy = 0;
            headTemp->data = curr%10;
            headTemp = headTemp->next;
        }
        head = reverseList(head);
        if(dummy == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};