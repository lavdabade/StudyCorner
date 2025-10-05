#include<iostream>
#include<vector>

using namespace std;

// User function Template for C++
class Solution {
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int di[] = {1, 0, -1, 0};
        int dj[] = {0, 1, 0, -1};
        for(int i=0; i<n; i++) {
            if(mat[i][0] == 'O') {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(mat[i][m-1] == 'O') {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }
        for(int j=0; j<m; j++) {
            if(mat[0][j] == 'O') {
                q.push({0, j});
                vis[0][j] = 1;
            }
            if(mat[n-1][j] == 'O') {
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
                if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==0 && mat[ni][nj]=='O') {
                    q.push({ni, nj});
                    vis[ni][nj] = 1;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j]==0) {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};