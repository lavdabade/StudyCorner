#include<iostream>
#include<vector>

using namespace std;

// User function Template for C++
class Solution {
  private:
    void numberOfEnclaves(vector<vector<int>> &grid, vector<vector<int>> &vis, int ci, int cj, int n, int m, int di[], int dj[]) {
        vis[ci][cj] = 1;
        for(int i=0; i<4; i++) {
            int ni = ci + di[i];
            int nj = cj + dj[i];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]==1) 
                numberOfEnclaves(grid, vis, ni, nj, n, m, di, dj);
        }
    }
    
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        int di[] = {1, 0, -1, 0};
        int dj[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            if(grid[i][0] == 1 && !vis[i][0]) numberOfEnclaves(grid, vis, i, 0, n, m, di, dj);
            if(grid[i][m-1] == 1 && !vis[i][m-1]) numberOfEnclaves(grid, vis, i, m-1, n, m, di, dj);
        }
        for(int j=0; j<m; j++) {
            if(grid[0][j] == 1 && !vis[0][j]) numberOfEnclaves(grid, vis, 0, j, n, m, di, dj);
            if(grid[n-1][j] == 1 && !vis[n-1][j]) numberOfEnclaves(grid, vis, n-1, j, n, m, di, dj);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j]==0 && grid[i][j]==1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
