#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    void topoSortUtil(int node, vector<int> &vis, vector<int>adj[], vector<int> &ans) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(vis[it] == 0) {
                topoSortUtil(it, vis, adj, ans);
            }
        }
        ans.push_back(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> ans;
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++) {
            if(vis[i]==0) {
                topoSortUtil(i, vis, adj, ans);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};