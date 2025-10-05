#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  private:
    bool isBST(Node* root, int minValue, int maxValue) {
        if(!root) return true;
        if(minValue > root->data || root->data > maxValue) return false;
        return isBST(root->left, minValue, root->data) && isBST(root->right, root->data, maxValue);
    }
    
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        return isBST(root, INT_MIN, INT_MAX);
    }
};