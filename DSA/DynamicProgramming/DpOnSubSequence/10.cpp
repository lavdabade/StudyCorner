#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<int> prev(capacity+1, 0);
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(capacity+1, 0);
            for(int rmg=1; rmg<=capacity; rmg++) {
                int take = 0;
                if(wt[idx] <= rmg) take = val[idx] + curr[rmg-wt[idx]];
                int notTake = prev[rmg];
                curr[rmg] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[capacity];
    }
};



class Solution_Tabulation {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
        for(int idx=n-1; idx>=0; idx--) {
            for(int rmg=1; rmg<=capacity; rmg++) {
                int take = 0;
                if(wt[idx] <= rmg) take = val[idx] + dp[idx][rmg-wt[idx]];
                int notTake = dp[idx+1][rmg];
                dp[idx][rmg] = max(take, notTake);
            }
        }
        return dp[0][capacity];
    }
};



class Solution_Memoization {
  private:
    int knapSackUtil(int idx, int rmg, int n, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
        if(idx == n || rmg == 0) return 0;
        if(dp[idx][rmg] != -1) return dp[idx][rmg];
        int take = 0;
        if(wt[idx] <= rmg) take = val[idx] + knapSackUtil(idx, rmg-wt[idx], n, wt, val, dp);
        int notTake = knapSackUtil(idx+1, rmg, n, wt, val, dp);
        return dp[idx][rmg] = max(take, notTake);
    }
    
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        return knapSackUtil(0, capacity, n, wt, val, dp);
    }
};



class Solution_Recursion {
  private:
    int knapSackUtil(int idx, int rmg, int n, vector<int> &wt, vector<int> &val) {
        if(idx == n || rmg == 0) return 0;
        int take = 0;
        if(wt[idx] <= rmg) take = val[idx] + knapSackUtil(idx, rmg-wt[idx], n, wt, val);
        int notTake = knapSackUtil(idx+1, rmg, n, wt, val);
        return max(take, notTake);
    }
    
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        return knapSackUtil(0, capacity, n, wt, val);
    }
};