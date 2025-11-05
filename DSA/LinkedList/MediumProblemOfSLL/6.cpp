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
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* fast = head;
        Node* slow = head;
        bool containLoop = false;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                containLoop = true;
                break;
            }
        }
        if(!containLoop) return 0;
        int ans = 1;
        fast = fast->next;
        while(fast != slow) {
            fast = fast->next;
            ans++;
        }
        return ans;
    }
};