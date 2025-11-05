#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        sum += d;
        if(sum % 2 == 1) return 0;
        sum /= 2;
        int n = arr.size();
        vector<int> prev(sum+1, 0);
        prev[0] = 1;
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(sum+1, 0);
            for(int rmg=0; rmg<=sum; rmg++) {
                int take = 0;
                if(arr[idx] <= rmg) {
                    take = prev[rmg - arr[idx]];
                }
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
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        sum += d;
        if(sum % 2 == 1) return 0;
        sum /= 2;
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int idx=0; idx<=n; idx++) {
            dp[idx][0] = 1;
        }
        for(int idx=n-1; idx>=0; idx--) {
            for(int rmg=0; rmg<=sum; rmg++) {
                int take = 0;
                if(arr[idx] <= rmg) {
                    take = dp[idx+1][rmg - arr[idx]];
                }
                int notTake = dp[idx+1][rmg];
                dp[idx][rmg] = (take + notTake);
            }
        }
        return dp[0][sum];
    }
};



class Solution_Memoization {
  private:
    int countPartitionsUtil(int idx, int rmg, int n, vector<int> &arr, vector<vector<int>> &dp) {
        if(rmg == 0) return 1;
        if(idx == n) return 0;
        if(dp[idx][rmg] != -1) return dp[idx][rmg];
        int take = 0;
        if(arr[idx] <= rmg) {
            take = countPartitionsUtil(idx+1, rmg - arr[idx], n, arr, dp);
        }
        int notTake = countPartitionsUtil(idx+1, rmg, n, arr, dp);
        return dp[idx][rmg] = (take + notTake);
    }
    
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        sum += d;
        if(sum % 2 == 1) return 0;
        sum /= 2;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return countPartitionsUtil(0, sum, n, arr, dp);
    }
};



class Solution_Recursion {
  private:
    int countPartitionsUtil(int idx, int rmg, int n, vector<int> &arr) {
        if(rmg == 0) return 1;
        if(idx == n) return 0;
        int take = 0;
        if(arr[idx] <= rmg) {
            take = countPartitionsUtil(idx+1, rmg - arr[idx], n, arr);
        }
        int notTake = countPartitionsUtil(idx+1, rmg, n, arr);
        return take + notTake;
    }
    
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        sum += d;
        if(sum % 2 == 1) return 0;
        sum /= 2;
        int n = arr.size();
        return countPartitionsUtil(0, sum, n, arr);
    }
};