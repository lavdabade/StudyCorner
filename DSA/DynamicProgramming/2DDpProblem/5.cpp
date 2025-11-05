#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        int n = triangle.size();
        vector<int> prev = triangle[n-1];
        for(int i=n-2; i>=0; i--) {
            vector<int> curr(i+1);
            for(int j=i; j>=0; j--) {
                curr[j] = triangle[i][j] + min(prev[j], prev[j+1]);
            }
            prev = curr;
        }
        return prev[0];
    }
};



class Solution_Tabulation {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int j=0; j<n; j++) dp[n-1][j] = triangle[n-1][j];
        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};



class Solution_Memoization {
  private:
    int minPathSumUtil(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
        if(i==n-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = triangle[i][j] + min(minPathSumUtil(i+1, j, n, triangle, dp), minPathSumUtil(i+1, j+1, n, triangle, dp));
    }
    
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        int n = triangle.size();
        vector<vector<int>> dp(n-1, vector<int>(n, -1));
        return minPathSumUtil(0, 0, n, triangle, dp);
    }
};



class Solution_Recursion {
  private:
    int minPathSumUtil(int i, int j, int n, vector<vector<int>> &triangle) {
        if(i==n-1) return triangle[i][j];
        return triangle[i][j] + min(minPathSumUtil(i+1, j, n, triangle), minPathSumUtil(i+1, j+1, n, triangle));
    }
    
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        int n = triangle.size();
        return minPathSumUtil(0, 0, n, triangle);
    }
};