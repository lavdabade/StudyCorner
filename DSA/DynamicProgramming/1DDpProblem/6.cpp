#include<iostream>
#include<map>

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
    int robUtil(TreeNode* root, map<TreeNode*, int> &mp) {
        if(!root) return 0;
        if(mp.find(root) != mp.end()) return mp[root];
        int take = root->val;
        if(root->left) {
            take += robUtil(root->left->left, mp);
            take += robUtil(root->left->right, mp);
        }
        if(root->right) {
            take += robUtil(root->right->left, mp);
            take += robUtil(root->right->right, mp);
        }
        int notTake = robUtil(root->left, mp) + robUtil(root->right, mp);
        return mp[root] = max(take, notTake);
    }

public:
    int rob(TreeNode* root) {
        map<TreeNode*, int> mp;
        return robUtil(root, mp);
    }
};



class Solution_Recursion {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        int take = root->val;
        if(root->left) {
            take += rob(root->left->left);
            take += rob(root->left->right);
        }
        if(root->right) {
            take += rob(root->right->left);
            take += rob(root->right->right);
        }
        int notTake = rob(root->left) + rob(root->right);
        return max(take, notTake);
    }
};