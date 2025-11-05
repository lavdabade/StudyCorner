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
  private:
    Node* reverseList(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        Node* headPtr = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return headPtr;
    }
    
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        Node* ans = new Node(-1);
        Node* ansHead = ans;
        int carry = 0;
        while(head1!=NULL || head2!=NULL || carry==1) {
            int sum = carry;
            if(head1) {
                sum += head1->data;
                head1 = head1->next;
            }
            if(head2) {
                sum += head2->data;
                head2 = head2->next;
            }
            Node* newNode = new Node(sum%10);
            ans->next = newNode;
            ans = ans->next;
            carry = sum/10;
        }
        ansHead = ansHead->next;
        ansHead = reverseList(ansHead);
        while(ansHead!=NULL && ansHead->data==0) ansHead=ansHead->next;
        return ansHead;
    }
};