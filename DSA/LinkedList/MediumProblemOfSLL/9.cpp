#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution {
  public:
    Node* removeKthNode(Node* head, int K)
    {
        // Write your code here.
        Node* prev = head;
        Node* next = head;
        while(K--) next = next->next;
        if(next == NULL) return head->next;
        while(next!=NULL && next->next!=NULL) {
            next = next->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};