#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

// User function Template for C++
class Solution {
  private:
    vector<vector<int>> bfs(int ci, int cj, vector<vector<int>> &vis, vector<vector<int>> &grid, int di[], int dj[], int n, int m, int mi, int mj) {
        vector<vector<int>> pos;
        pos.push_back({ci-mi, cj-mj});
        queue<pair<int, int>> q;
        q.push({ci, cj});
        vis[ci][cj] = 1;
        while(!q.empty()) {
            ci = q.front().first;
            cj = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int ni = ci + di[i];
                int nj = cj + dj[i];
                if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==0 && grid[ni][nj]==1) {
                    q.push({ni, nj});
                    vis[ni][nj] = 1;
                    pos.push_back({ni-mi, nj-mj});
                }
            }
        }
        return pos;
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
                    st.insert(bfs(i, j, vis, grid, di, dj, n, m, i, j));
                }
            }
        }
        return st.size();
    }
};
