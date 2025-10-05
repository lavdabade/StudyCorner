#include<iostream>
#include<map>
#include<set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void populateParentNode(TreeNode* root, map<TreeNode*, TreeNode*> &mp) {
        if(!root) return;
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        populateParentNode(root->left, mp);
        populateParentNode(root->right, mp);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*, TreeNode*> parentMap;
        set<TreeNode*> vis;
        populateParentNode(root, parentMap);
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);
        while(!q.empty()) {
            if(k==0) break;
            k--;
            int sz = q.size();
            while(sz--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && vis.find(node->left)==vis.end()) {
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right && vis.find(node->right)==vis.end()) {
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(parentMap.count(node)>0 && vis.find(parentMap[node])==vis.end()) {
                    q.push(parentMap[node]);
                    vis.insert(parentMap[node]);
                }
            }
        }
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};