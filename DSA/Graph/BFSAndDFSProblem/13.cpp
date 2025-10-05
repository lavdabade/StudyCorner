#include<iostream>
#include<vector>

using namespace std;

// User function Template for C++
class Solution {
  private:
    void fillUtil(vector<vector<char>> &mat, vector<vector<int>> &vis, int ci, int cj, int n, int m, int di[], int dj[]) {
        vis[ci][cj] = 1;
        for(int i=0; i<4; i++) {
            int ni = ci + di[i];
            int nj = cj + dj[i];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && mat[ni][nj]=='O') 
                fillUtil(mat, vis, ni, nj, n, m, di, dj);
        }
    }
  
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int di[] = {1, 0, -1, 0};
        int dj[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            if(mat[i][0] == 'O' && !vis[i][0]) fillUtil(mat, vis, i, 0, n, m, di, dj);
            if(mat[i][m-1] == 'O' && !vis[i][m-1]) fillUtil(mat, vis, i, m-1, n, m, di, dj);
        }
        for(int j=0; j<m; j++) {
            if(mat[0][j] == 'O' && !vis[0][j]) fillUtil(mat, vis, 0, j, n, m, di, dj);
            if(mat[n-1][j] == 'O' && !vis[n-1][j]) fillUtil(mat, vis, n-1, j, n, m, di, dj);
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