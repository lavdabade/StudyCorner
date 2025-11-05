#include<iostream>
#include<vector>

using namespace std;

// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n == 1) return arr[0];
        int prev2 = arr[0];
        int prev1 = max(arr[0], arr[1]);
        for(int idx=2; idx<n; idx++) {
            int curr = max(prev1, arr[idx] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

// User function template for C++
class Solution_Tabulation {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int idx=2; idx<n; idx++) {
            dp[idx] = max(dp[idx-1], arr[idx] + dp[idx-2]);
        }
        return dp[n-1];
    }
};


// User function template for C++
class Solution_Memoization {
  private:
    int findMaxSumUtil(int idx, vector<int> &arr, vector<int> &dp) {
        if(idx == 0) return arr[0];
        if(idx == 1) return max(arr[0], arr[1]);
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max(findMaxSumUtil(idx-1, arr, dp), arr[idx] + findMaxSumUtil(idx-2, arr, dp));
    }
    
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, -1);
        return findMaxSumUtil(n-1, arr, dp);
    }
};


// User function template for C++
class Solution_Recursion {
  private:
    int findMaxSumUtil(int idx, vector<int> &arr) {
        if(idx == 0) return arr[0];
        if(idx == 1) return max(arr[0], arr[1]);
        return max(findMaxSumUtil(idx-1, arr), arr[idx] + findMaxSumUtil(idx-2, arr));
    }
    
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        return findMaxSumUtil(n-1, arr);
    }
};