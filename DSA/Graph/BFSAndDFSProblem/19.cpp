#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    bool isBipartite(int node, vector<int> &vis, vector<int> adj[]) {
        for(auto it: adj[node]) {
            if(vis[it] == -1) {
                vis[it] = 1-vis[node];
                if(!isBipartite(it, vis, adj)) return false;
            }
            else if(vis[it]==vis[node]) return false;
        }
        return true;
    }
    
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> vis(V, -1);
        vector<int> adj[V];
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<V; i++) {
            if(vis[i]==-1) {
                vis[i]=0;
                if(!isBipartite(i, vis, adj))
                    return false;
            }
        }
        return true;
    }
};