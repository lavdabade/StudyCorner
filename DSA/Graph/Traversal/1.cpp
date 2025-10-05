#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vis[0]=1;
        ans.push_back(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it]=1;
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};