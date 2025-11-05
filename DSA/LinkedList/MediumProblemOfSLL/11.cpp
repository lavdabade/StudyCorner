#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    Node* mergeList(Node* head1, Node* head2) {
        Node* ans = new Node(-1);
        Node* ansHead = ans;
        while(head1!=NULL && head2!=NULL) {
            if(head1->data < head2->data) {
                ans->next = head1;
                head1 = head1->next;
            }
            else {
                ans->next = head2;
                head2 = head2->next;
            }
            ans = ans->next;
        }
        while(head1!=NULL) {
            ans->next = head1;
            ans = ans->next;
            head1 = head1->next;
        }
        while(head2!=NULL) {
            ans->next = head2;
            ans = ans->next;
            head2 = head2->next;
        }
        ans->next = NULL;
        return ansHead->next;
    }
    
    Node* getMiddle(Node* head) {
        Node* fast = head->next;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
  public:
    Node* mergeSort(Node* head) {
        // code here
        if(head == NULL || head->next == NULL) return head;
        Node* middle = getMiddle(head);
        Node* middleNext = middle->next;
        middle->next = NULL;
        Node* left = mergeSort(head);
        Node* right = mergeSort(middleNext);
        return mergeList(left, right);
    }
};