#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<int> adj[n];
        vector<int> inOrder(n, 0);
        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
            inOrder[it[0]]++;
        }
        int topoCount = 0;
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(inOrder[i] == 0) {
                q.push(i);
            }
        }
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
        return (n==topoCount);
    }
};