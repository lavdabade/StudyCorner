#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    void dfs(int node, vector<int> &vis, vector<int> &ans, vector<vector<int>> &adj) {
        ans.push_back(node);
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, ans, adj);
            }
        }
    }
  
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        dfs(0, vis, ans, adj);
        return ans;
    }
};