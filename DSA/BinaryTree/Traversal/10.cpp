#include<iostream>
#include<vector>

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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root) {
            TreeNode* leftNode = root->left;
            if(!leftNode) {
                ans.push_back(root->val);
                root=root->right;
            }
            else {
                while(leftNode->right && leftNode->right->val!=root->val) leftNode=leftNode->right;
                if(leftNode->right) {
                    leftNode->right = NULL;
                    root=root->right;
                }
                else {
                    ans.push_back(root->val);
                    leftNode->right = root;
                    root = root->left;
                }
            }
        }
        return ans;
    }
};