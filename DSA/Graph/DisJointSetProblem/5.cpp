#include<iostream>
#include<vector>

using namespace std;

class DisJoint {
  private:
    int n;
    vector<int> rank;
    vector<int> parent;
    
  public:
    DisJoint(int n) {
        this->n = n;
        rank.resize(n, 0);
        parent.resize(n);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    
    void unionByRank(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if(up == vp) return;
        if(rank[up] > rank[vp]) parent[vp] = up;
        else if(rank[vp] > rank[up]) parent[up] = vp;
        else {
            parent[vp] = up;
            rank[up]++;
        }
    }
    
    int getNoOfComponents() {
        int comp = 0;
        for(int i=0; i<n; i++) {
            if(parent[i] == i && rank[i]>0) {
                comp++;
            }
        }
        return comp;
    }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        int n = 0;
        int m = 0;
        int num = stones.size();
        for(auto it: stones) {
            n = max(n, it[0]);
            m = max(m, it[1]);
        }
        DisJoint ds(n+m+2);
        for(auto it: stones) {
            int u = it[0];
            int v = n+it[1]+1;
            ds.unionByRank(v, u);
        }
        return num - ds.getNoOfComponents();
    }
};