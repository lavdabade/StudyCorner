#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    void findCircleNum(int node, vector<int> &vis, vector<int> adj[]) {
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            node = q.front();
            q.pop();
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n = isConnected.size();
        vector<int> adj[n+1];
        vector<int> vis(n+1, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j && isConnected[i][j]==1) {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                ans++;
                findCircleNum(i, vis, adj);
            }
        }
        return ans;
    }
};