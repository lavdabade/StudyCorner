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
    int maxPathSumUtil(TreeNode* root, int &ans) {
        if(!root) return 0;
        int leftPathSum = max(maxPathSumUtil(root->left, ans), 0);
        int rightPathSum = max(maxPathSumUtil(root->right, ans), 0);
        ans = max(ans, root->val + leftPathSum + rightPathSum);
        return root->val + max(leftPathSum, rightPathSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPathSumUtil(root, ans);
        return ans;
    }
};