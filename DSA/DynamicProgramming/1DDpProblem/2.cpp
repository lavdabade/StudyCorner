#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        if(n == 1) return 0;
        int prev2 = 0;
        int prev1 = abs(height[1] - height[0]);
        for(int idx=2; idx<n; idx++) {
            int curr = min(abs(height[idx] - height[idx-1]) + prev1, abs(height[idx] - height[idx-2]) + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

class Solution_Tabulation {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        for(int idx=2; idx<n; idx++) {
            dp[idx] = min(abs(height[idx] - height[idx-1]) + dp[idx-1], abs(height[idx] - height[idx-2]) + dp[idx-2]);
        }
        return dp[n-1];
    }
};

class Solution_Memoization {
  private:
    int minCostUtil(int idx, vector<int> &height, vector<int> &dp) {
        if(idx == 0) return dp[idx] = 0;
        if(idx == 1) return dp[idx] = abs(height[1] - height[0]);
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = min(abs(height[idx] - height[idx-1]) + minCostUtil(idx-1, height, dp), abs(height[idx] - height[idx-2]) + minCostUtil(idx-2, height, dp));
    }
  
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        minCostUtil(n-1, height, dp);
        return dp[n-1];
    }
};


class Solution_Recursion {
  private:
    int minCostUtil(int idx, vector<int> &height) {
        if(idx == 0) return 0;
        if(idx == 1) return abs(height[1] - height[0]);
        return min(abs(height[idx] - height[idx-1]) + minCostUtil(idx-1, height), abs(height[idx] - height[idx-2]) + minCostUtil(idx-2, height));
    }
  
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        return minCostUtil(n-1, height);
    }
};