#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// User function Template for C++
class Solution {
  private:
    void articulationPointsUtil(int node, int parent, vector<int> &vis, vector<int> &t, vector<int> &m, int &timer, vector<int> &a, vector<int> adj[]) {
        vis[node] = 1;
        t[node] = timer;
        m[node] = timer;
        timer++;
        int child = 0;
        for(auto it: adj[node]) {
            if(it == parent) continue;
            if(vis[it] == 1) {
                m[node] = min(m[node], t[it]);
            }
            else {
                articulationPointsUtil(it, node, vis, t, m, timer, a, adj);
                m[node] = min(m[node], m[it]);
                if(m[it] >= t[node] && parent!=-1) {
                    a[node] = 1;
                }
                child++;
            }
        }
        if(parent == -1 && child > 1) a[node] = 1;
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(V, 0);
        vector<int> t(V);
        vector<int> m(V);
        vector<int> a(V, 0);
        int timer = 0;
        articulationPointsUtil(0, -1, vis, t, m, timer, a, adj);
        for(int i=0; i<V; i++) {
            if(a[i] == 1) {
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) ans.push_back(-1);
        return ans;
    }
};