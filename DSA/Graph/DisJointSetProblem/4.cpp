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
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        int extra = 0;
        DisJoint ds(V);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int up = ds.findParent(u);
            int vp = ds.findParent(v);
            if(up == vp) extra++;
            else {
                ds.unionBySize(u, v);
            }
        }
        int noOfComp = 0;
        for(int i=0; i<V; i++) {
            if(ds.findParent(i) == i) {
                noOfComp++;
            }
        }
        int req = noOfComp - 1;
        if(req > extra) return -1;
        return req;
    }
};
