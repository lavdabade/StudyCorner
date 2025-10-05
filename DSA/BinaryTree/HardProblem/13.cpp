#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void flatten(Node *root) {
        // code here
        Node* head = root;
        while(root) {
            if(root->left) {
                Node* prev = root->left;
                while(prev->right) prev=prev->right;
                prev->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};