#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

class Solution {
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        int sum = accumulate(A.begin(), A.end(), 0);
        if(abs(target) > sum) return 0;
        target += sum;
        if(target % 2 == 1) return 0;
        target /= 2;
        vector<int> prev(target+1, 0);
        prev[0] = 1;
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(target+1, 0);
            curr[0] = 1;
            for(int rmg=1; rmg<=target; rmg++) {
                long long take = 0;
                if(A[idx] <= rmg) take = prev[rmg-A[idx]];
                long long notTake = prev[rmg];
                curr[rmg] = (take + notTake);
            }
            prev = curr;
        }
        return prev[target];
    }
};



//Back-end complete function Template for C++
class Solution_Tabulation {
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        int sum = accumulate(A.begin(), A.end(), 0);
        if(abs(target) > sum) return 0;
        target += sum;
        if(target % 2 == 1) return 0;
        target /= 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int idx=0; idx<=n; idx++) {
            dp[idx][0] = 1;
        }
        for(int idx=n-1; idx>=0; idx--) {
            for(int rmg=1; rmg<=target; rmg++) {
                long long take = 0;
                if(A[idx] <= rmg) take = dp[idx+1][rmg-A[idx]];
                long long notTake = dp[idx+1][rmg];
                dp[idx][rmg] = (take + notTake);
            }
        }
        return dp[0][target];
    }
};



//Back-end complete function Template for C++
class Solution_Memoization {
  private:
    long long findTargetSumWaysUtil(int idx, int target, int n, vector<int> &A, vector<vector<int>> &dp) {
        if(target == 0) return 1;
        if(idx == n) return 0;
        if(dp[idx][target] != -1) return dp[idx][target];
        long long take = 0;
        if(A[idx] <= target) take = findTargetSumWaysUtil(idx+1, target-A[idx], n, A, dp);
        long long notTake = findTargetSumWaysUtil(idx+1, target, n, A, dp);
        return dp[idx][target] = (take + notTake);
    }
    
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        int sum = accumulate(A.begin(), A.end(), 0);
        if(abs(target) > sum) return 0;
        target += sum;
        if(target % 2 == 1) return 0;
        target /= 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return findTargetSumWaysUtil(0, target, n, A, dp);
    }
};



//Back-end complete function Template for C++
class Solution_Recursion {
  private:
    long long findTargetSumWaysUtil(int idx, int target, int n, vector<int> &A) {
        if(target == 0) return 1;
        if(idx == n) return 0;
        long long take = 0;
        if(A[idx] <= target) take = findTargetSumWaysUtil(idx+1, target-A[idx], n, A);
        long long notTake = findTargetSumWaysUtil(idx+1, target, n, A);
        return take + notTake;
    }
    
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        int sum = accumulate(A.begin(), A.end(), 0);
        if(abs(target) > sum) return 0;
        target += sum;
        if(target % 2 == 1) return 0;
        target /= 2;
        return findTargetSumWaysUtil(0, target, n, A);
    }
};