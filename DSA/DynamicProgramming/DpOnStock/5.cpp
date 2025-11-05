#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    long long maximumProfit(vector<long long>& prices, int n) {
        // Code here
        vector<long long> prev1(2, 0);
        vector<long long> prev2(2, 0);
        for(int idx=n-1; idx>=0; idx--) {
            vector<long long> curr(2, 0);
            for(int canBuy=0; canBuy<=1; canBuy++) {
                if(canBuy) curr[canBuy] = max(prev1[1], -prices[idx] + prev1[0]);
                else curr[canBuy] = max(prev1[0], prices[idx] + prev2[1]);
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[1];
    }
};



class Solution_Tabulation {
  public:
    long long maximumProfit(vector<long long>& prices, int n) {
        // Code here
        vector<vector<long long>> dp(n+2, vector<long long>(2, 0));
        for(int idx=n-1; idx>=0; idx--) {
            for(int canBuy=0; canBuy<=1; canBuy++) {
                if(canBuy) dp[idx][canBuy] = max(dp[idx+1][1], -prices[idx] + dp[idx+1][0]);
                else dp[idx][canBuy] = max(dp[idx+1][0], prices[idx] + dp[idx+2][1]);
            }
        }
        return dp[0][1];
    }
};



class Solution_Memoization {
  private:
    long long maximumProfitUtil(int idx, int canBuy, int n, vector<long long> &prices, vector<vector<long long>> &dp) {
        if(idx >= n) return 0;
        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        if(canBuy) return dp[idx][canBuy] = max(maximumProfitUtil(idx+1, 1, n, prices, dp), -prices[idx] + maximumProfitUtil(idx+1, 0, n, prices, dp));
        else return dp[idx][canBuy] = max(maximumProfitUtil(idx+1, 0, n, prices, dp), prices[idx] + maximumProfitUtil(idx+2, 1, n, prices, dp));
    }
  
  public:
    long long maximumProfit(vector<long long>& prices, int n) {
        // Code here
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return maximumProfitUtil(0, 1, n, prices, dp);
    }
};



class Solution_Recursion {
  private:
    long long maximumProfitUtil(int idx, int canBuy, int n, vector<long long> &prices) {
        if(idx >= n) return 0;
        if(canBuy) return max(maximumProfitUtil(idx+1, 1, n, prices), -prices[idx] + maximumProfitUtil(idx+1, 0, n, prices));
        else return max(maximumProfitUtil(idx+1, 0, n, prices), prices[idx] + maximumProfitUtil(idx+2, 1, n, prices));
    }
  
  public:
    long long maximumProfit(vector<long long>& prices, int n) {
        // Code here
        return maximumProfitUtil(0, 1, n, prices);
    }
};