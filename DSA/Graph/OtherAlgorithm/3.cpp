#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//Position this line where user code will be pasted.
class Solution {
  private:
    void dfs1(int node, stack<int> &st, vector<int> &vis, vector<vector<int>> &adj) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(vis[it] == 0) {
                dfs1(it, st, vis, adj);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<int> &vis, vector<vector<int>> &adjT) {
        vis[node] = 0;
        for(auto it: adjT[node]) {
            if(vis[it] == 1) {
                dfs2(it, vis, adjT);
            }
        }
    }
    
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        stack<int> st;
        vector<int> vis(n, 0);
        vector<vector<int>> adjT(n);
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs1(i, st, vis, adj);
            }
            for(auto it: adj[i]) {
                adjT[it].push_back(i);
            }
        }
        int ans = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(vis[node] == 1) {
                dfs2(node, vis, adjT);
                ans++;
            }
        }
        return ans;
    }
};