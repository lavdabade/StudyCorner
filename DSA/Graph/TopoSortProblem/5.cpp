#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    void findOrderUtil(int node, vector<int> adj[], vector<int> &ans, vector<int> &vis) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(vis[it] == 0) {
                findOrderUtil(it, adj, ans, vis);
            }
        }
        ans.push_back(node);
    }
    
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> adj[n];
        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                findOrderUtil(i, adj, ans, vis);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};