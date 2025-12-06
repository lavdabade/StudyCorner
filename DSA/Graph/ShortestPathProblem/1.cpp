#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int> adj[V];
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(V, -1);
        queue<int> q;
        ans[src] = 0;
        q.push(src);
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(auto it: adj[front]) {
                if(ans[it]==-1 || (ans[it] > ans[front]+1)) {
                    ans[it] = ans[front]+1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
