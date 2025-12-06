#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int, int>> adj[V];
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> ans(V, -1);
        ans[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(auto it: adj[front]) {
                if(ans[it.first] == -1 || (ans[it.first] > ans[front] + it.second)) {
                    ans[it.first] = ans[front] + it.second;
                    q.push(it.first);
                }
            }
        }
        return ans;
    }
};
