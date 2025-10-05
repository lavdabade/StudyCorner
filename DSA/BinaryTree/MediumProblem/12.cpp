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
    int countNodes(Node* root) {
        // Write your code here
        if(!root) return 0;
        Node* node = root;
        int left = 0;
        while(node) {
            node=node->left;
            left++;
        }
        node = root;
        int right = 0;
        while(node) {
            node=node->right;
            right++;
        }
        if(left == right) return (1<<left)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};