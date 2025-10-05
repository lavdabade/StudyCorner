#include<iostream>
#include<vector>

using namespace std;


class Solution {
  private:
    void bfs(int node, vector<int> &vis, vector<int> adj[], vector<vector<int>> &ans) {
        vis[node]=1;
        vector<int> temp;
        temp.push_back(node);
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            node = q.front();
            q.pop();
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it]=1;
                    temp.push_back(it);
                    q.push(it);
                }
            }
        }
        ans.push_back(temp);
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
                bfs(i, vis, adj, ans);
            }
        }
        return ans;
    }
};
