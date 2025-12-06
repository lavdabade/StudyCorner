#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        vector<int> inOrder(V, 0);
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            inOrder[it[1]]++;
        }
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(inOrder[i] == 0) {
                q.push(i);
            }
        }
        int topoCount = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topoCount++;
            for(auto it: adj[node]) {
                inOrder[it]--;
                if(inOrder[it] == 0) {
                    q.push(it);
                }
            }
        }
        return (V!=topoCount);
    }
};