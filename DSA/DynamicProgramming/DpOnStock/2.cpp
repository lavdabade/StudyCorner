#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<int> prev(2, 0);
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(2, 0);
            for(int canBuy=0; canBuy<=1; canBuy++) {
                if(canBuy) curr[canBuy] = max(prev[1], -prices[idx] + prev[0]);
                else curr[canBuy] = max(prev[0], prices[idx] + prev[1]);
            }
            prev = curr;
        }
        return prev[1];
    }
};


class Solution_Tabulation {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int idx=n-1; idx>=0; idx--) {
            for(int canBuy=0; canBuy<=1; canBuy++) {
                if(canBuy) dp[idx][canBuy] = max(dp[idx+1][1], -prices[idx] + dp[idx+1][0]);
                else dp[idx][canBuy] = max(dp[idx+1][0], prices[idx] + dp[idx+1][1]);
            }
        }
        return dp[0][1];
    }
};



class Solution_Memoization {
  private:
    int maximumProfitUtil(int idx, int canBuy, int n, vector<int> &prices, vector<vector<int>> &dp) {
        if(idx == n) return 0;
        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        if(canBuy) return dp[idx][canBuy] = max(maximumProfitUtil(idx+1, 1, n, prices, dp), -prices[idx] + maximumProfitUtil(idx+1, 0, n, prices, dp));
        else return dp[idx][canBuy] = max(maximumProfitUtil(idx+1, 0, n, prices, dp), prices[idx] + maximumProfitUtil(idx+1, 1, n, prices, dp));
    }
    
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int canBuy = 1;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maximumProfitUtil(0, canBuy, n, prices, dp);
    }
};



class Solution_Recursion {
  private:
    int maximumProfitUtil(int idx, int canBuy, int n, vector<int> &prices) {
        if(idx == n) return 0;
        if(canBuy) return max(maximumProfitUtil(idx+1, 1, n, prices), -prices[idx] + maximumProfitUtil(idx+1, 0, n, prices));
        else return max(maximumProfitUtil(idx+1, 0, n, prices), prices[idx] + maximumProfitUtil(idx+1, 1, n, prices));
    }
    
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int canBuy = 1;
        return maximumProfitUtil(0, canBuy, n, prices);
    }
};