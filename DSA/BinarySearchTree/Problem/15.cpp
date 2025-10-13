#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class NodeDetails {
  public:
    int minValue;
    int maxValue;
    int treeSize;
    
    NodeDetails(int minValue, int maxValue, int treeSize) {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->treeSize = treeSize;
    }
};

class Solution {
  private:
    NodeDetails* largestBstUtil(Node* root) {
        if(!root) return new NodeDetails(INT_MAX, INT_MIN, 0);
        NodeDetails* leftDetails = largestBstUtil(root->left);
        NodeDetails* rightDetails = largestBstUtil(root->right);
        if(root->data > leftDetails->maxValue && root->data < rightDetails->minValue) 
            return new NodeDetails(min(root->data, leftDetails->minValue), max(root->data, rightDetails->maxValue), leftDetails->treeSize+rightDetails->treeSize+1);
        return new NodeDetails(INT_MIN, INT_MAX, max(leftDetails->treeSize, rightDetails->treeSize));
    }
  
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        NodeDetails* ans = largestBstUtil(root);
        return ans->treeSize;
    }
};