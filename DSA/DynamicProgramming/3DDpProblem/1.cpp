#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int solve(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prev(m, vector<int>(m));
        for(int j1=0; j1<m; j1++) {
            for(int j2=0; j2<m; j2++) {
                if(j1==j2) prev[j1][j2] = grid[n-1][j1];
                else prev[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        for(int i=n-2; i>=0; i--) {
            vector<vector<int>> curr(m, vector<int>(m));
            for(int j1=m-1; j1>=0; j1--) {
                for(int j2=0; j2<=m-1; j2++) {
                    int ans = 0;
                    for(int _j1=-1; _j1<=1; _j1++) {
                        for(int _j2=-1; _j2<=1; _j2++) {
                            if((j1+_j1) < 0 || (j1+_j1) == m || (j2+_j2) < 0 || (j2+_j2) == m) continue;
                            ans = max(ans, prev[j1+_j1][j2+_j2]);
                        }
                    }
                    curr[j1][j2] = ans + ((j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]);
                }
            }
            prev = curr;
        }
        return prev[0][m-1];
    }
};



class Solution_Tabulation {
  public:
    int solve(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m)));
        for(int j1=0; j1<m; j1++) {
            for(int j2=0; j2<m; j2++) {
                if(j1==j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        for(int i=n-2; i>=0; i--) {
            for(int j1=m-1; j1>=0; j1--) {
                for(int j2=0; j2<=m-1; j2++) {
                    int ans = 0;
                    for(int _j1=-1; _j1<=1; _j1++) {
                        for(int _j2=-1; _j2<=1; _j2++) {
                            if((j1+_j1) < 0 || (j1+_j1) == m || (j2+_j2) < 0 || (j2+_j2) == m) continue;
                            ans = max(ans, dp[i+1][j1+_j1][j2+_j2]);
                        }
                    }
                    dp[i][j1][j2] = ans + ((j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]);
                }
            }
        }
        return dp[0][0][m-1];
    }
};



class Solution_Memoization {
  private:
    int solveUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if(i==n-1) {
            int ans = 0;
            if(j1 == j2) ans = max(ans, grid[i][j1]);
            else ans = max(ans, grid[i][j1] + grid[i][j2]);
            return dp[i][j1][j2] = ans;
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int ans = 0;
        for(int _j1=-1; _j1<=1; _j1++) {
            for(int _j2=-1; _j2<=1; _j2++) {
                if((j1+_j1) < 0 || (j1+_j1) == m || (j2+_j2) < 0 || (j2+_j2) == m) continue;
                ans = max(ans, solveUtil(i+1, j1+_j1, j2+_j2, n, m, grid, dp));
            }
        }
        return dp[i][j1][j2] = ans + ((j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]);
    }
    
  public:
    int solve(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        int j1 = 0;
        int j2 = m-1;
        int i = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solveUtil(i, j1, j2, n, m, grid, dp);
    }
};



class Solution_Recursion {
  private:
    int solveUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid) {
        if(i==n-1) {
            int ans = 0;
            if(j1 == j2) ans = max(ans, grid[i][j1]);
            else ans = max(ans, grid[i][j1] + grid[i][j2]);
            return ans;
        }
        int ans = 0;
        for(int _j1=-1; _j1<=1; _j1++) {
            for(int _j2=-1; _j2<=1; _j2++) {
                if((j1+_j1) < 0 || (j1+_j1) == m || (j2+_j2) < 0 || (j2+_j2) == m) continue;
                ans = max(ans, solveUtil(i+1, j1+_j1, j2+_j2, n, m, grid));
            }
        }
        return ans + ((j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]);
    }
    
  public:
    int solve(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        int j1 = 0;
        int j2 = m-1;
        int i = 0;
        return solveUtil(i, j1, j2, n, m, grid);
    }
};