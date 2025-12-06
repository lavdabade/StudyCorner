#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int, int>> adj[V];
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> ans(V, INT_MAX);
        ans[src] = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(src);
        while(!pq.empty()) {
            int top = pq.top();
            pq.pop();
            for(auto it: adj[top]) {
                if(ans[it.first] > (ans[top] + it.second)) {
                    ans[it.first] = ans[top] + it.second;
                    pq.push(it.first);
                }
            }
        }
        return ans;
    }
};