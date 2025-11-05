#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);
        Node* zeroHead = zero;
        Node* oneHead = one;
        Node* twoHead = two;
        while(head) {
            if(head->data == 0) {
                zero->next = head;
                zero = zero->next;
            }
            else if(head->data == 1) {
                one->next = head;
                one = one->next;
            }
            else {
                two->next = head;
                two = two->next;
            }
            head = head->next;
        }
        two->next=NULL;
        one->next = twoHead->next;
        zero->next = oneHead->next;
        return zeroHead->next;
    }
};