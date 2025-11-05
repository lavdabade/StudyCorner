#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n, 0);
        for(int idx=n-2; idx>=0; idx--) {
            int ans = INT_MAX;
            for(int jump=1; (jump <= k) && (idx+jump < n); jump++) {
                ans = min(ans, abs(arr[idx] - arr[idx+jump]) + dp[idx+jump]);
            }
            dp[idx] = ans;
        }
        return dp[0];
    }
};



class Solution_Memoization {
  private:
    int minimizeCostUtil(int idx, int k, int n, vector<int> &arr, vector<int> &dp) {
        if(idx == n-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int ans = INT_MAX;
        for(int jump=1; (jump <= k) && (idx+jump < n); jump++) {
            ans = min(ans, abs(arr[idx] - arr[idx+jump]) + minimizeCostUtil(idx+jump, k, n, arr, dp));
        }
        return dp[idx] = ans;
    }
    
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n-1, -1);
        return minimizeCostUtil(0, k, n, arr, dp);
    }
};



class Solution_Recursion {
  private:
    int minimizeCostUtil(int idx, int k, int n, vector<int> &arr) {
        if(idx == n-1) return 0;
        int ans = INT_MAX;
        for(int jump=1; (jump <= k) && (idx+jump < n); jump++) {
            ans = min(ans, abs(arr[idx] - arr[idx+jump]) + minimizeCostUtil(idx+jump, k, n, arr));
        }
        return ans;
    }
    
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        return minimizeCostUtil(0, k, n, arr);
    }
};