#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int freshCount = 0;
        int di[] = {1, 0, -1, 0};
        int dj[] = {0, 1, 0, -1};
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 1) freshCount++;
                else if(mat[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        if(freshCount==0) return 0;
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            while(sz--) {
                int ci = q.front().first;
                int cj = q.front().second;
                q.pop();
                for(int i=0; i<4; i++) {
                    int ni = ci + di[i];
                    int nj = cj + dj[i];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==0 && mat[ni][nj]==1) {
                        vis[ni][nj]=1;
                        freshCount--;
                        q.push({ni, nj});
                    }
                }
            }
        }
        if(freshCount!=0) return -1;
        return ans-1;
    }
};