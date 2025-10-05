#include<iostream>

using namespace std;

class Solution {
  private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &temp) {
        vis[node]=1;
        temp.push_back(node);
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, temp);
            }
        }
    }
    
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> ans;
        vector<int> vis(V, 0);
        vector<int> adj[V];
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                vector<int> temp;
                dfs(i, vis, adj, temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
