#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        k *= 2;
        int n = prices.size();
        vector<int> prev(k+1, 0);
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(k+1, 0);
            for(int trans=1; trans<=k; trans++) {
                if(trans%2 == 0) curr[trans] = max(prev[trans], -prices[idx] + prev[trans-1]);
                else curr[trans] = max(prev[trans], prices[idx] + prev[trans-1]);
            }
            prev = curr;
        }
        return prev[k];
    }
};



class Solution_Tabulation {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        k *= 2;
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for(int idx=n-1; idx>=0; idx--) {
            for(int trans=1; trans<=k; trans++) {
                if(trans%2 == 0) dp[idx][trans] = max(dp[idx+1][trans], -prices[idx] + dp[idx+1][trans-1]);
                else dp[idx][trans] = max(dp[idx+1][trans], prices[idx] + dp[idx+1][trans-1]);
            }
        }
        return dp[0][k];
    }
};



class Solution_Memoization {
  private:
    int maxProfitUtil(int idx, int k ,int n, vector<int> &prices, vector<vector<int>> &dp) {
        if(idx == n || k == 0) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        if(k%2 == 0) return dp[idx][k] = max(maxProfitUtil(idx+1, k, n, prices, dp), -prices[idx] + maxProfitUtil(idx+1, k-1, n, prices, dp));
        else return dp[idx][k] = max(maxProfitUtil(idx+1, k, n, prices, dp), prices[idx] + maxProfitUtil(idx+1, k-1, n, prices, dp));
    }
    
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        k *= 2;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return maxProfitUtil(0, k, n, prices, dp);
    }
};



class Solution_Recursion {
  private:
    int maxProfitUtil(int idx, int k ,int n, vector<int> &prices) {
        if(idx == n || k == 0) return 0;
        if(k%2 == 0) return max(maxProfitUtil(idx+1, k, n, prices), -prices[idx] + maxProfitUtil(idx+1, k-1, n, prices));
        else return max(maxProfitUtil(idx+1, k, n, prices), prices[idx] + maxProfitUtil(idx+1, k-1, n, prices));
    }
    
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        k *= 2;
        int n = prices.size();
        return maxProfitUtil(0, k, n, prices);
    }
};