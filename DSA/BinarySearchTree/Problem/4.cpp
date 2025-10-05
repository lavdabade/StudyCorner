#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    Node* deleteNodeUtil(Node* root) {
        if(root->left==NULL && root->right == NULL) return NULL;
        else if(root->left == NULL && root->right != NULL) return root->right;
        else if(root->left != NULL && root->right == NULL) return root->left;
        else {
            Node* prev = root->left;
            while(prev->right) {
                prev = prev->right;
            }
            prev->right = root->right;
            return root->left;
        }
    }

  public:
    Node *deleteNode(Node *root, int x) {
        // code here
        if(root->data == x) return deleteNodeUtil(root);
        Node* head = root;
        while(root) {
            if(root->data > x) {
                if(root->left == NULL) return head;
                if(root->left->data == x) {
                    root->left = deleteNodeUtil(root->left);
                    return head;
                }
                root = root->left;
            }
            else {
                if(root->right == NULL) return head;
                if(root->right->data == x) {
                    root->right = deleteNodeUtil(root->right);
                    return head;
                }
                root = root->right;
            }
        }
        return head;
    }
};