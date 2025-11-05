#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ansMain = INT_MAX;
        vector<int> prev(m);
        for(int j=0; j<m; j++) {
            prev[j] = mat[n-1][j];
        }
        for(int i=n-2; i>=0; i--) {
            vector<int> curr(m);
            for(int j=m-1; j>=0; j--) {
                int ans = prev[j];
                if(j!=0) ans = min(ans, prev[j-1]);
                if(j!=m-1) ans = min(ans, prev[j+1]);
                curr[j] = mat[i][j] + ans;
            }
            prev = curr;
        }
        for(int j=0; j<m; j++) {
            ansMain = min(ansMain, prev[j]);
        }
        return ansMain;
    }
};


class Solution_Tabulation {
private:
    void minFallingPathSumUtil(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        for(int i=n-2; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = dp[i+1][j];
                if(j!=0) ans = min(ans, dp[i+1][j-1]);
                if(j!=m-1) ans = min(ans, dp[i+1][j+1]);
                dp[i][j] = mat[i][j] + ans;
            }
        }
    }

public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m));
        for(int j=0; j<m; j++) {
            dp[n-1][j] = mat[n-1][j];
        }
        minFallingPathSumUtil(n, m, mat, dp);
        for(int j=0; j<m; j++) {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};



class Solution_Memoization {
private:
    int minFallingPathSumUtil(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        if(i==n-1) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = minFallingPathSumUtil(i+1, j, n, m, mat, dp);
        if(j!=0) ans = min(ans, minFallingPathSumUtil(i+1, j-1, n, m, mat, dp));
        if(j!=m-1) ans = min(ans, minFallingPathSumUtil(i+1, j+1, n, m, mat, dp));
        return dp[i][j] = mat[i][j] + ans;
    }

public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n-1, vector<int>(m, -1));
        for(int j=0; j<m; j++) {
            ans = min(ans, minFallingPathSumUtil(0, j, n, m, mat, dp));
        }
        return ans;
    }
};



class Solution_Recursion {
private:
    int minFallingPathSumUtil(int i, int j, int n, int m, vector<vector<int>> &mat) {
        if(i==n-1) return mat[i][j];
        int ans = minFallingPathSumUtil(i+1, j, n, m, mat);
        if(j!=0) ans = min(ans, minFallingPathSumUtil(i+1, j-1, n, m, mat));
        if(j!=m-1) ans = min(ans, minFallingPathSumUtil(i+1, j+1, n, m, mat));
        return mat[i][j] + ans;
    }

public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = INT_MAX;
        for(int j=0; j<m; j++) {
            ans = min(ans, minFallingPathSumUtil(0, j, n, m, mat));
        }
        return ans;
    }
};