#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    bool isCyclic(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]) {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(isCyclic(it, vis, pathVis, adj)) {
                    return true;
                }
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node]=0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(isCyclic(i, vis, pathVis, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};