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
    int floor(Node* root, int x) {
        // Code here
        int ans = -1;
        while(root) {
            if(root->data == x) return x;
            else if(root->data > x) root = root->left;
            else {
                ans = root->data;
                root = root->right;
            }
        }
        return ans;
    }
};