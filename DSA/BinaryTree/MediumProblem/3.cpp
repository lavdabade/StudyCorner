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
    int diameterOfBinaryTreeUtil(TreeNode* root, int &ans) {
        if(!root) return 0;
        int leftHeight = diameterOfBinaryTreeUtil(root->left, ans);
        int rightHeight = diameterOfBinaryTreeUtil(root->right, ans);
        ans = max(ans, leftHeight + rightHeight);
        return 1+max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        diameterOfBinaryTreeUtil(root, ans);
        return ans;
    }
};