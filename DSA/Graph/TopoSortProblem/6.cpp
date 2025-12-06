#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        vector<int> inOrder(V, 0);
        for(auto it: edges) {
            adj[it[1]].push_back(it[0]);
            inOrder[it[0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<V; i++) {
            if(inOrder[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]) {
                inOrder[it]--;
                if(inOrder[it]==0) {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};