#include<iostream>
#include<vector>
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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        vector<vector<int>> ans;
        queue<pair<int, pair<int, TreeNode*>>> q;
        q.push({0, {0, root}});
        while(!q.empty()) {
            int v = q.front().first;
            int h = q.front().second.first;
            TreeNode* n = q.front().second.second;
            q.pop();
            mp[v][h].push_back(n->val);
            if(n->left) q.push({v-1, {h+1, n->left}});
            if(n->right) q.push({v+1, {h+1, n->right}});
        }
        for(auto it: mp) {
            vector<int> temp;
            for(auto itt: it.second) {
                sort(itt.second.begin(), itt.second.end());
                temp.insert(temp.end(), itt.second.begin(), itt.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};