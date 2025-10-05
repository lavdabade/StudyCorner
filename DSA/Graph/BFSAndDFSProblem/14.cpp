#include<iostream>
#include<vector>

using namespace std;

// User function Template for C++
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &mat) {
        // Code here
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int di[] = {1, 0, -1, 0};
        int dj[] = {0, 1, 0, -1};
        for(int i=0; i<n; i++) {
            if(mat[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(mat[i][m-1] == 1) {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }
        for(int j=0; j<m; j++) {
            if(mat[0][j] == 1) {
                q.push({0, j});
                vis[0][j] = 1;
            }
            if(mat[n-1][j] == 1) {
                q.push({n-1, j}); 
                vis[n-1][j] = 1;
            }
        }
        while(!q.empty()) {
            int ci = q.front().first;
            int cj = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int ni = ci + di[i];
                int nj = cj + dj[i];
                if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==0 && mat[ni][nj]==1) {
                    q.push({ni, nj});
                    vis[ni][nj] = 1;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j]==0 && mat[i][j]==1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
