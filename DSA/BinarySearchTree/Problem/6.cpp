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

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int kthLargest(Node *root, int &k) {
        // Your code here
        if(!root) return -1;
        int right = kthLargest(root->right, k);
        if(right!=-1) return right;
        k--;
        if(k==0) return root->data;
        return kthLargest(root->left, k);
    }
};



