#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<int> prev(sum+1, 0);
        prev[0] = 1;
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(sum+1, 0);
            curr[0] = 1;
            for(int rmg=1; rmg<=sum; rmg++) {
                int take = 0;
                if(coins[idx] <= rmg) take = curr[rmg - coins[idx]];
                int notTake = prev[rmg];
                curr[rmg] = (take + notTake);
            }
            prev = curr;
        }
        return prev[sum];
    }
};



class Solution_Tabulation {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int idx=0; idx<=n; idx++) {
            dp[idx][0] = 1;
        }
        for(int idx=n-1; idx>=0; idx--) {
            for(int rmg=1; rmg<=sum; rmg++) {
                int take = 0;
                if(coins[idx] <= rmg) take = dp[idx][rmg - coins[idx]];
                int notTake = dp[idx+1][rmg];
                dp[idx][rmg] = (take + notTake);
            }
        }
        return dp[0][sum];
    }
};



class Solution_Memoization {
  private:
    int countUtil(int idx, int rmg, int n, vector<int> &coins, vector<vector<int>> &dp) {
        if(rmg == 0) return 1;
        if(idx == n) return 0;
        if(dp[idx][rmg] != -1) return dp[idx][rmg];
        int take = 0;
        if(coins[idx] <= rmg) take = countUtil(idx, rmg - coins[idx], n, coins, dp);
        int notTake = countUtil(idx+1, rmg, n, coins, dp);
        return dp[idx][rmg] = (take + notTake);
    }
    
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return countUtil(0, sum, n, coins, dp);
    }
};



class Solution_Recursion {
  private:
    int countUtil(int idx, int rmg, int n, vector<int> &coins) {
        if(rmg == 0) return 1;
        if(idx == n) return 0;
        int take = 0;
        if(coins[idx] <= rmg) take = countUtil(idx, rmg - coins[idx], n, coins);
        int notTake = countUtil(idx+1, rmg, n, coins);
        return take + notTake;
    }
    
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        return countUtil(0, sum, n, coins);
    }
};