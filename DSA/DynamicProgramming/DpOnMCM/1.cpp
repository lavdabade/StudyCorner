#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n-1, vector<int>(n-1, 0));
        for(int start=n-2; start>=0; start--) {
            for(int end=start+1; end<n-1; end++) {
                int ans = INT_MAX;
                for(int k=start+1; k<=end; k++) {
                    int curr = arr[start]*arr[k]*arr[end+1]
                             + dp[start][k-1]
                             + dp[k][end];
                    ans = min(ans, curr);
                }
                dp[start][end] = ans;
            }
        }
        return dp[0][n-2];
    }
};



class Solution_Memoization {
  private:
    int matrixMultiplicationUtil(int start, int end, vector<int> &arr, vector<vector<int>> &dp) {
        if(start == end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        for(int k=start+1; k<=end; k++) {
            int curr = arr[start]*arr[k]*arr[end+1]
                     + matrixMultiplicationUtil(start, k-1, arr, dp)
                     + matrixMultiplicationUtil(k, end, arr, dp);
            ans = min(ans, curr);
        }
        return dp[start][end] = ans;
    }
    
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n-1, vector<int>(n-1, -1));
        return matrixMultiplicationUtil(0, n-2, arr, dp);
    }
};



class Solution_Recursion {
  private:
    int matrixMultiplicationUtil(int start, int end, vector<int> &arr) {
        if(start == end) return 0;
        int ans = INT_MAX;
        for(int k=start+1; k<=end; k++) {
            int curr = arr[start]*arr[k]*arr[end+1]
                     + matrixMultiplicationUtil(start, k-1, arr)
                     + matrixMultiplicationUtil(k, end, arr);
            ans = min(ans, curr);
        }
        return ans;
    }
    
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        return matrixMultiplicationUtil(0, n-2, arr);
    }
};