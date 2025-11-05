#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<int> prev(target+1, 0);
        prev[0] = 1;
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(target+1, 0);
            for(int rmg=0; rmg<=target; rmg++) {
                int take = 0;
                if(arr[idx] <= rmg) take = prev[rmg - arr[idx]];
                int notTake = prev[rmg];
                curr[rmg] = (take + notTake);
            }
            prev = curr;
        }
        return prev[target];
    }
};



class Solution_Tabulation {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int idx=0; idx<=n; idx++) {
            dp[idx][0] = 1;
        }
        for(int idx=n-1; idx>=0; idx--) {
            for(int rmg=0; rmg<=target; rmg++) {
                int take = 0;
                if(arr[idx] <= rmg) take = dp[idx+1][rmg - arr[idx]];
                int notTake = dp[idx+1][rmg];
                dp[idx][rmg] = (take + notTake);
            }
        }
        return dp[0][target];
    }
};



class Solution_Memoization {
  private:
    int perfectSumUtil(int idx, int rmg, int n, vector<int> &arr, vector<vector<int>> &dp) {
        if(rmg == 0) return 1;
        if(idx == n) return 0;
        if(dp[idx][rmg] != -1) return dp[idx][rmg];
        int take = 0;
        if(arr[idx] <= rmg) take = perfectSumUtil(idx+1, rmg - arr[idx], n, arr, dp);
        int notTake = perfectSumUtil(idx+1, rmg, n, arr, dp);
        return dp[idx][rmg] = (take + notTake);
    }
    
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return perfectSumUtil(0, target, n, arr, dp);
    }
};



class Solution_Recursion {
  private:
    int perfectSumUtil(int idx, int rmg, int n, vector<int> &arr) {
        if(rmg == 0) return 1;
        if(idx == n) return 0;
        int take = 0;
        if(arr[idx] <= rmg) take = perfectSumUtil(idx+1, rmg - arr[idx], n, arr);
        int notTake = perfectSumUtil(idx+1, rmg, n, arr);
        return take + notTake;
    }
    
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return perfectSumUtil(0, target, n, arr);
    }
};