#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    grid[i][j] = 0;
                }
            }
        }
        int temp = 0;
        while(!q.empty()) {
            int sz = q.size();
            temp++;
            while(sz--) {
                int ci = q.front().first;
                int cj = q.front().second;
                q.pop();
                for(int i=0; i<4; i++) {
                    int ni = ci + di[i];
                    int nj = cj + dj[i];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==0) {
                        q.push({ni, nj});
                        grid[ni][nj] = temp;
                        vis[ni][nj] = 1;
                    }
                }
            }
        }
        return grid;
    }
};