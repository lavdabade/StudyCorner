#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<int> prev(sum+1, 0);
        prev[0] = 1;
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(sum+1, 0);
            curr[0] = 1;
            for(int rmgSum=1; rmgSum<=sum; rmgSum++) {
                bool take = false;
                if(arr[idx] <= rmgSum) take = prev[rmgSum-arr[idx]];
                bool notTake = prev[rmgSum];
                curr[rmgSum] = (take || notTake);
            }
            prev = curr;
        }
        return prev[sum];
    }
};



class Solution_tabulation {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int idx=0; idx<n; idx++) {
            dp[idx][0] = 1;
        }
        for(int idx=n-1; idx>=0; idx--) {
            for(int rmgSum=1; rmgSum<=sum; rmgSum++) {
                bool take = false;
                if(arr[idx] <= rmgSum) take = dp[idx+1][rmgSum-arr[idx]];
                bool notTake = dp[idx+1][rmgSum];
                dp[idx][rmgSum] = (take || notTake);
            }
        }
        return dp[0][sum];
    }
};



class Solution_Memoization {
  private:
    bool isSubsetSumUtil(int idx, int sum, int n, vector<int> &arr, vector<vector<int>> &dp) {
        if(sum == 0) return true;
        if(idx == n) return false;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool take = false;
        if(arr[idx] <= sum) take = isSubsetSumUtil(idx+1, sum-arr[idx], n, arr, dp);
        bool notTake = isSubsetSumUtil(idx+1, sum, n, arr, dp);
        return dp[idx][sum] = (take || notTake);
    }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return isSubsetSumUtil(0, sum, n, arr, dp);
    }
};



class Solution_Recursion {
  private:
    bool isSubsetSumUtil(int idx, int sum, int n, vector<int> &arr) {
        if(sum == 0) return true;
        if(idx == n) return false;
        bool take = false;
        if(arr[idx] <= sum) take = isSubsetSumUtil(idx+1, sum-arr[idx], n, arr);
        bool notTake = isSubsetSumUtil(idx+1, sum, n, arr);
        return take || notTake;
    }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        return isSubsetSumUtil(0, sum, n, arr);
    }
};