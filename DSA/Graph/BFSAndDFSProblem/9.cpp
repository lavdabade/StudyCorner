#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int topoSortCount = 0;
        vector<int> adj[V];
        vector<int> inOrder(V, 0);
        queue<int> q;
        for(auto it: edges) {
            inOrder[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0; i<V; i++) {
            if(inOrder[i]==0) {
                topoSortCount++;
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it: adj[node]) {
                inOrder[it]--;
                if(inOrder[it]==0) {
                    q.push(it);
                    topoSortCount++;
                }
            }
        }
        return topoSortCount != V;
    }
};