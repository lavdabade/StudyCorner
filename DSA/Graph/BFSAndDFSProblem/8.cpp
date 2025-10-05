#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    bool isCycle(int node, vector<int> &vis, vector<int> adj[], int parent) {
        vis[node]=1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(isCycle(it, vis, adj, node)) 
                    return true;
            }
            else if(it != parent) return true;
        }
        return false;
    }
  
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++)
            if(!vis[i]) 
                if(isCycle(i, vis, adj, -1))
                    return true;
        return false;
    }
};