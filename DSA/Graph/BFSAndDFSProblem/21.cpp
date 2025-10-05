#include<iostream>
#include<vector>
#include<set>

using namespace std;

// User function Template for C++
class Solution {
  private:
    void dfs(int ci, int cj, vector<vector<int>> &vis, vector<vector<int>> &grid, int di[], int dj[], vector<vector<int>> &temp, int n, int m, int mi, int mj) {
        vis[ci][cj]=1;
        temp.push_back({ci-mi, cj-mj});
        for(int i=0; i<4; i++) {
            int ni = ci + di[i];
            int nj = cj + dj[i];
            if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==0 && grid[ni][nj]==1) 
                dfs(ni, nj, vis, grid, di, dj, temp, n, m, mi, mj);
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<vector<int>>> st;
        int di[] = {1, 0, -1, 0};
        int dj[] = {0, 1, 0, -1};
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1 && vis[i][j]==0) {
                    vector<vector<int>> temp;
                    dfs(i, j, vis, grid, di, dj, temp, n, m, i, j);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};
