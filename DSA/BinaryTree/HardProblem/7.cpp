#include<iostream>

template <typename T>
class BinaryTreeNode
{
    public:
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL || (root->left==NULL && root->right==NULL)) return;
    int left = 0;
    if(root->left) left = root->left->data;
    int right = 0;
    if(root->right) right = root->right->data;
    if(left+right < root->data) {
        if(root->left) root->left->data += root->data-left-right;
        else root->right->data += root->data-left-right;
    }
    changeTree(root->left);
    changeTree(root->right);
    if(root->left) left = root->left->data;
    if(root->right) right = root->right->data;
    root->data = left+right;
}  