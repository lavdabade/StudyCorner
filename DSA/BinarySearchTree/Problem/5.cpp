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

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int &k) {
        // add code here.
        if(!root) return -1;
        int left = kthSmallest(root->left, k);
        if(left!=-1) return left;
        k--;
        if(k==0) return root->data;
        return kthSmallest(root->right, k);
    }
};