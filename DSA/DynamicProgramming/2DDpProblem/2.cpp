#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int numberOfPaths(int n, int m) {
        // Code Here
        vector<int> prev(m, 1);
        for(int i=n-2; i>=0; i--) {
            vector<int> curr(m);
            curr[m-1]=1;
            for(int j=m-2; j>=0; j--) {
                curr[j] = prev[j] + curr[j+1];
            }
            prev = curr;
        }
        return prev[0];
    }
};



class Solution_Tabulation {
  public:
    int numberOfPaths(int n, int m) {
        // Code Here
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) dp[i][m-1] = 1;
        for(int j=0; j<m; j++) dp[n-1][j] = 1;
        for(int i=n-2; i>=0; i--) {
            for(int j=m-2; j>=0; j--) {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};



class Solution_Memoization {
  private:
    int numberOfPathsUtil(int i, int j, int n, int m, vector<vector<int>> &dp) {
        if(i==n-1 && j==m-1) return 1;
        if(i==n || j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = numberOfPathsUtil(i+1, j, n, m, dp) + numberOfPathsUtil(i, j+1, n, m, dp);
    }
    
  public:
    int numberOfPaths(int n, int m) {
        // Code Here
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return numberOfPathsUtil(0, 0, n, m, dp);
    }
};



class Solution_Recursion {
  private:
    int numberOfPathsUtil(int i, int j, int n, int m) {
        if(i==n-1 && j==m-1) return 1;
        if(i==n || j==m) return 0;
        return numberOfPathsUtil(i+1, j, n, m) + numberOfPathsUtil(i, j+1, n, m);
    }
    
  public:
    int numberOfPaths(int n, int m) {
        // Code Here
        return numberOfPathsUtil(0, 0, n, m);
    }
};
