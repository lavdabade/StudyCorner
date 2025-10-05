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
    int getCount(Node* head) {
        // Code here
        int ans=0;
        while(head) {
            ans++;
            head=head->next;
        }
        return ans;
    }
};