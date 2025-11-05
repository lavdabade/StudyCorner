#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node *next;

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
    bool isPalindrome(Node *head) {
        //  code here
        Node* fast = head->next;
        Node* slow = head;
        if(fast == NULL) return true;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        Node* head2 = slow->next;
        slow->next = NULL;
        head2 = reverseList(head2);
        Node* head1Temp = head;
        Node* head2Temp = head2;
        while(head2Temp!=NULL) {
            if(head1Temp->data != head2Temp->data) {
                head2 = reverseList(head2);
                slow->next = head2;
                return false;
            }
            head1Temp = head1Temp->next;
            head2Temp = head2Temp->next;
        }
        return true;
    }
};