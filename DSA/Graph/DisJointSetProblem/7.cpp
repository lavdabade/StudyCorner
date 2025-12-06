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
    
    int getSize(int n) {
        return size[n];
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
    int largestIsland(vector<vector<int>>& grid) {
        // Your code goes here.
        int n = grid.size();
        DisJoint ds(n*n);
        int cnt = 0;
        int di[] = {1, 0, -1, 0};
        int dj[] = {0, 1, 0, -1};
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    cnt++;
                    for(int k=0; k<4; k++) {
                        int ni = i+di[k];
                        int nj = j+dj[k];
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj] == 1) {
                            ds.unionBySize(i*n+j, ni*n+nj);
                        }
                    }
                }
            }
        }
        if((n*n) - cnt <= 1) return n*n;
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    set<int> st;
                    for(int k=0; k<4; k++) {
                        int ni = i+di[k];
                        int nj = j+dj[k];
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj] == 1) {
                            st.insert(ds.findParent(ni*n+nj));
                        }
                    }
                    int curr = 0;
                    for(auto it: st) {
                        curr += ds.getSize(ds.findParent(it));
                    }
                    ans = max(ans, curr+1);
                }
            }
        }
        return ans;
    }
};