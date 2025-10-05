#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution {
  public:
    int minValue(Node* root) {
        // code here
        if(!root) return -1;
        while(root->left) root = root->left;
        return root->data;
    }
};