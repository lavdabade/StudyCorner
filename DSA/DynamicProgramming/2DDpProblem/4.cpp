#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m);
        for(int i=n-1; i>=0; i--) {
            vector<int> curr(m);
            for(int j=m-1; j>=0; j--) {
                if(i==n-1 && j==m-1) curr[j] = grid[i][j];
                else {
                    int right = INT_MAX;
                    int down = INT_MAX;
                    if(j<m-1) right = curr[j+1];
                    if(i<n-1) down = prev[j];
                    curr[j] = grid[i][j] + min(right, down); 
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};



class Solution_Tabulation {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(i==n-1 && j==m-1) dp[i][j] = grid[i][j];
                else {
                    int right = INT_MAX;
                    int down = INT_MAX;
                    if(j<m-1) right = dp[i][j+1];
                    if(i<n-1) down = dp[i+1][j];
                    dp[i][j] = grid[i][j] + min(right, down); 
                }
            }
        }
        return dp[0][0];
    }
};



class Solution_Memoization {
private:
    int minPathSumUtil(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i==n-1 && j==m-1) return grid[n-1][m-1];
        int right = INT_MAX;
        int down = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        if(j<m-1) right = minPathSumUtil(i, j+1, n, m, grid, dp);
        if(i<n-1) down = minPathSumUtil(i+1, j, n, m, grid, dp);
        return dp[i][j] = grid[i][j] + min(right, down); 
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minPathSumUtil(0, 0, n, m, grid, dp);
    }
};



class Solution_Recursion {
private:
    int minPathSumUtil(int i, int j, int n, int m, vector<vector<int>> &grid) {
        if(i==n-1 && j==m-1) return grid[n-1][m-1];
        int right = INT_MAX;
        int down = INT_MAX;
        if(j<m-1) right = minPathSumUtil(i, j+1, n, m, grid);
        if(i<n-1) down = minPathSumUtil(i+1, j, n, m, grid);
        return grid[i][j] + min(right, down); 
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return minPathSumUtil(0, 0, n, m, grid);
    }
};