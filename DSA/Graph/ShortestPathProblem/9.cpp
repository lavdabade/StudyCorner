#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj[V];
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dis(V, 1e18);
        vector<int> cnt(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        dis[0] = 0;
        cnt[0] = 1;
        while(!q.empty()) {
            int node = q.top().second;
            int wt = q.top().first;
            q.pop();
            if(wt > dis[node]) continue;
            for(auto it: adj[node]) {
                if(dis[it[0]] > dis[node] + it[1]) {
                    dis[it[0]] = dis[node] + it[1];
                    q.push({dis[it[0]], it[0]});
                    cnt[it[0]] = cnt[node];
                }
                else if(dis[it[0]] == dis[node] + it[1]) {
                    cnt[it[0]] += cnt[node];
                }
            }
        }
        return cnt[V-1];
    }
};