#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        vector<int> prev(2, 0);
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(2, 0);
            for(int canBuy=0; canBuy<=1; canBuy++) {
                if(canBuy) curr[canBuy] = max(prev[1], -arr[idx] + prev[0]);
                else curr[canBuy] = max(prev[0], arr[idx] + prev[1] - k);
            }
            prev = curr;
        }
        return prev[1];
    }
};



class Solution_Tabulation {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int idx=n-1; idx>=0; idx--) {
            for(int canBuy=0; canBuy<=1; canBuy++) {
                if(canBuy) dp[idx][canBuy] = max(dp[idx+1][1], -arr[idx] + dp[idx+1][0]);
                else dp[idx][canBuy] = max(dp[idx+1][0], arr[idx] + dp[idx+1][1] - k);
            }
        }
        return dp[0][1];
    }
};



class Solution_Memoization {
  private:
    int maxProfitUtil(int idx, int canBuy, int k, int n, vector<int> &arr, vector<vector<int>> &dp) {
        if(idx == n) return 0;
        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        if(canBuy) return dp[idx][canBuy] = max(maxProfitUtil(idx+1, 1, k, n, arr, dp), -arr[idx] + maxProfitUtil(idx+1, 0, k, n, arr, dp));
        else return dp[idx][canBuy] = max(maxProfitUtil(idx+1, 0, k, n, arr, dp), arr[idx] + maxProfitUtil(idx+1, 1, k, n, arr, dp) - k);
    }
    
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxProfitUtil(0, 1, k, n, arr, dp);
    }
};



class Solution_Recursion {
  private:
    int maxProfitUtil(int idx, int canBuy, int k, int n, vector<int> &arr) {
        if(idx == n) return 0;
        if(canBuy) return max(maxProfitUtil(idx+1, 1, k, n, arr), -arr[idx] + maxProfitUtil(idx+1, 0, k, n, arr));
        else return max(maxProfitUtil(idx+1, 0, k, n, arr), arr[idx] + maxProfitUtil(idx+1, 1, k, n, arr) - k);
    }
    
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        return maxProfitUtil(0, 1, k, n, arr);
    }
};