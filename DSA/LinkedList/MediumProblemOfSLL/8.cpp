#include<iostream>

using namespace std;

// User function template for C++
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
  public:
    Node* divide(Node* head) {
        // code here
        Node* even = new Node(-1);
        Node* odd = new Node(-1);
        Node* evenHead = even;
        Node* oddHead = odd;
        while(head) {
            if((head->data%2) == 0) {
                even->next = head;
                even = even->next;
            }
            else {
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;
        }
        odd->next = NULL;
        even->next = oddHead->next;
        return evenHead->next;
    }
};