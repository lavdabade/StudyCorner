#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool isSymmetricUtil(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return ((p->val==q->val) && (isSymmetricUtil(p->left, q->right)) && (isSymmetricUtil(p->right, q->left)));
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetricUtil(root->left, root->right);
    }
};