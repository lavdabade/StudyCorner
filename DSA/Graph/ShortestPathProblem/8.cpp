#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj[V];
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> delay(V, 1e9);
        delay[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it: adj[node]) {
                if(delay[it[0]] > delay[node] + it[1]) {
                    delay[it[0]] = delay[node] + it[1];
                    q.push(it[0]);
                }
            }
        }
        int maxDelay = *max_element(delay.begin(), delay.end());
        if(maxDelay == 1e9) return -1;
        return maxDelay;
    }
};