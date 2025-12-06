#include<iostream>
#include<vector>
#include<set>

using namespace std;

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
            size[vp] += size[up];
            parent[up] = vp;
        }
        else {
            size[up] += size[vp];
            parent[vp] = up;
        }
    }
};

// User function Template for C++
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int noOfIsland = 0;
        vector<int> ans;
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        DisJoint ds(n*m);
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(auto it: operators) {
            int ci = it[0];
            int cj = it[1];
            if(grid[ci][cj] == 1) {
                ans.push_back(noOfIsland);
                continue;
            }
            grid[ci][cj] = 1;
            noOfIsland++;
            set<int> st;
            for(int i=0; i<4; i++) {
                int ni = ci + di[i];
                int nj = cj + dj[i];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj] == 1) {
                    st.insert(ds.findParent(ni*m+nj));
                }
            }
            for(auto it: st) {
                ds.unionBySize(ci*m+cj, it);
            }
            noOfIsland -= st.size();
            ans.push_back(noOfIsland);
        }
        return ans;
    }
};