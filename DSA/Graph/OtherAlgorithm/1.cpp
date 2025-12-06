#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
private:
    void criticalConnectionsUtil(int node, int parent, vector<int> &vis, vector<int> &t, vector<int> &m, 
                                 int &timer, vector<vector<int>> &ans, vector<int> adj[]) { 
        vis[node] = 1; 
        t[node] = timer; 
        m[node] = timer; 
        timer++; 
        for(auto it: adj[node]) 
        { 
            if(it == parent) continue; 
            if(vis[it] == 1) { 
                m[node] = min(m[node], t[it]); 
            } 
            else { 
                criticalConnectionsUtil(it, node, vis, t, m, timer, ans, adj); 
                m[node] = min(m[node], m[it]); 
                if(m[it] > t[node]) { 
                    ans.push_back({node, it}); 
                }
            } 
        } 
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<int> vis(n, 0);
        vector<int> t(n, -1);
        vector<int> m(n, -1);
        int timer = 0;
        vector<int> adj[n];
        for(auto it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                criticalConnectionsUtil(i, -1, vis, t, m, timer, ans, adj);
            }
        }
        return ans;
    }
};