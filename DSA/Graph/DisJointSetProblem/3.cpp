#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// User function Template for C++
class DisJoint {
  private:
    vector<int> parent;
    vector<int> size;

  public:
    DisJoint(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    
    void unionBySize(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if(up == vp) return;
        if(size[up] < size[vp]) {
            parent[up] = vp;
            size[vp] += size[up];
        }
        else {
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(auto it: edges) {
            pq.push({it[2], {it[0], it[1]}});
        }
        int ans = 0;
        DisJoint ds(V);
        while(!pq.empty()) {
            int w = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            if(ds.findParent(u) != ds.findParent(v)) {
                ds.unionBySize(u, v);
                ans += w;
            }
        }
        return ans;
    }
};