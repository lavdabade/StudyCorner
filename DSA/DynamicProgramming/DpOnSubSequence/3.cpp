#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> prev(sum+1, 0);
        prev[0] = 1;
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(sum+1, 0);
            for(int rmgSum=0; rmgSum<=sum; rmgSum++) {
                bool take = false;
                if(arr[idx] <= rmgSum) {
                    take = prev[rmgSum-arr[idx]];
                }
                bool notTake = prev[rmgSum];
                curr[rmgSum] = (take || notTake);
            }
            prev = curr;
        }
        for(int tempSum=sum/2; tempSum>0; tempSum--) {
            if(prev[tempSum]) {
                return ((sum-tempSum) - tempSum);
            }
        }
        return sum;
    }
};



class Solution_tabulation {
  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int idx=0; idx<=n; idx++) {
            dp[idx][0] = 1;
        }
        for(int idx=n-1; idx>=0; idx--) {
            for(int rmgSum=0; rmgSum<=sum; rmgSum++) {
                bool take = false;
                if(arr[idx] <= rmgSum) {
                    take = dp[idx+1][rmgSum-arr[idx]];
                }
                bool notTake = dp[idx+1][rmgSum];
                dp[idx][rmgSum] = (take || notTake);
            }
        }
        for(int tempSum=sum/2; tempSum>0; tempSum--) {
            if(dp[0][tempSum]) {
                return ((sum-tempSum) - tempSum);
            }
        }
        return sum;
    }
};



class Solution_Memoization {
  private:
    bool minDifferenceUtil(int idx, int rmgSum, int n, vector<int> &arr, vector<vector<int>> &dp) {
        if(rmgSum == 0) return true;
        if(idx == n) return false;
        if(dp[idx][rmgSum] != -1) return dp[idx][rmgSum];
        bool take = false;
        if(arr[idx] <= rmgSum) {
            take = minDifferenceUtil(idx+1, rmgSum-arr[idx], n, arr, dp);
        }
        bool notTake = minDifferenceUtil(idx+1, rmgSum, n, arr, dp);
        return dp[idx][rmgSum] = (take || notTake);
    }

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        for(int tempSum=sum/2; tempSum>0; tempSum--) {
            if(minDifferenceUtil(0, tempSum, n, arr, dp)) {
                return ((sum-tempSum) - tempSum);
            }
        }
        return sum;
    }
};



class Solution_Recursion {
  private:
    bool minDifferenceUtil(int idx, int rmgSum, int n, vector<int> &arr) {
        if(rmgSum == 0) return true;
        if(idx == n) return false;
        bool take = false;
        if(arr[idx] <= rmgSum) {
            take = minDifferenceUtil(idx+1, rmgSum-arr[idx], n, arr);
        }
        bool notTake = minDifferenceUtil(idx+1, rmgSum, n, arr);
        return take || notTake;
    }

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        for(int tempSum = sum/2; tempSum>0; tempSum--) {
            if(minDifferenceUtil(0, tempSum, n, arr)) {
                return (sum-tempSum)-tempSum;
            }
        }
        return sum;
    }
};
