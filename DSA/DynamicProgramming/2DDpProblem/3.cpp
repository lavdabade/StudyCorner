#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        vector<int> prev(m+1, 0);
        for(int i=n-1; i>=0; i--) {
            vector<int> curr(m+1);
            for(int j=m-1; j>=0; j--) {
                if(i==n-1 && j==m-1) curr[j] = 1;
                else if(grid[i][j] == 1) continue;
                else curr[j] = prev[j] + curr[j+1];
            }
            prev = curr;
        }
        return prev[0];
    }
};



class Solution_Tabulation {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[n-1][m-1] = 1;
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if((i==n-1 && j==m-1) || grid[i][j] == 1) continue;
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};



class Solution_Memoization {
  private:
    int uniquePathsUtil(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i==n-1 && j==m-1) return 1;
        if(i==n || j==m) return 0;
        if(grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = uniquePathsUtil(i+1, j, n, m, grid, dp) + uniquePathsUtil(i, j+1, n, m, grid, dp);
    }
    
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return uniquePathsUtil(0, 0, n, m, grid, dp);
    }
};



class Solution_Recursion {
  private:
    int uniquePathsUtil(int i, int j, int n, int m, vector<vector<int>> &grid) {
        if(i==n-1 && j==m-1) return 1;
        if(i==n || j==m) return 0;
        if(grid[i][j] == 1) return 0;
        return uniquePathsUtil(i+1, j, n, m, grid) + uniquePathsUtil(i, j+1, n, m, grid);
    }
    
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        return uniquePathsUtil(0, 0, n, m, grid);
    }
};