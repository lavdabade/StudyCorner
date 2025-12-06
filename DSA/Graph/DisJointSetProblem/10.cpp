#include<iostream>
#include<vector>

using namespace std;

class DisJoint {
  private:
    vector<int> size;
    vector<int> parent;
    
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
        if(size[up] > size[vp]) {
            parent[vp] = up;
            size[up] += size[vp];
        }
        else {
            parent[up] = vp;
            size[vp] += size[up];
        }
    }
};

class Solution {
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        DisJoint ds(V);
        for(auto it: edges) {
            if((it[0] == c && it[1] == d) || (it[1] == c && it[0] == d)) continue;
            ds.unionBySize(it[0], it[1]);
        }
        if(ds.findParent(c) == ds.findParent(d)) return false;
        return true;
    }
};