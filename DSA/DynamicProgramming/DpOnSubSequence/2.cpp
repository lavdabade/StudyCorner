#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 2 == 1) return false;
        sum /= 2;
        vector<int> prev(sum+1, 0);
        prev[0] = 1;
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(sum+1, 0);
            curr[0] = 1;
            for(int currSum=1; currSum<=sum; currSum++) {
                bool take = false;
                if(arr[idx] <= currSum) {
                    take = prev[currSum-arr[idx]];
                }
                bool notTake = prev[currSum];
                curr[currSum] = (take || notTake);
            }
            prev = curr;
        }
        return prev[sum];
    }
};



class Solution_Tabulation {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 2 == 1) return false;
        sum /= 2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int idx=0; idx<=n; idx++) {
            dp[idx][0] = 1;
        }
        for(int idx=n-1; idx>=0; idx--) {
            for(int currSum=1; currSum<=sum; currSum++) {
                bool take = false;
                if(arr[idx] <= currSum) {
                    take = dp[idx+1][currSum-arr[idx]];
                }
                bool notTake = dp[idx+1][currSum];
                dp[idx][currSum] = (take || notTake);
            }
        }
        return dp[0][sum];
    }
};



class Solution_Memoization {
  private:
    bool equalPartitionUtil(int idx, int currSum, int n, vector<int> &arr, vector<vector<int>> &dp) {
        if(currSum == 0) return true;
        if(idx == n) return false;
        if(dp[idx][currSum] != -1) return dp[idx][currSum];
        bool take = false;
        if(arr[idx] <= currSum) {
            take = equalPartitionUtil(idx+1, currSum-arr[idx], n, arr, dp);
        }
        bool notTake = equalPartitionUtil(idx+1, currSum, n, arr, dp);
        return dp[idx][currSum] = (take || notTake);
    }
    
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 2 == 1) return false;
        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return equalPartitionUtil(0, sum, n, arr, dp);
    }
};



class Solution_Recursion {
  private:
    bool equalPartitionUtil(int idx, int currSum, int n, vector<int> &arr) {
        if(currSum == 0) return true;
        if(idx == n) return false;
        bool take = false;
        if(arr[idx] <= currSum) {
            take = equalPartitionUtil(idx+1, currSum-arr[idx], n, arr);
        }
        bool notTake = equalPartitionUtil(idx+1, currSum, n, arr);
        return take || notTake;
    }
    
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 2 == 1) return false;
        sum /= 2;
        return equalPartitionUtil(0, sum, n, arr);
    }
};