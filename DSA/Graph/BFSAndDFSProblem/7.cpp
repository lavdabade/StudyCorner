#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  private:
    bool isCycle(int node, vector<int> &vis, vector<int> adj[]) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        vis[node]=1;
        while(!q.empty()) {
            node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it: adj[node]) 
                if(!vis[it]) {
                    q.push({it, node});
                    vis[it] = 1;
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
                if(isCycle(i, vis, adj))
                    return true;
        return false;
    }
};