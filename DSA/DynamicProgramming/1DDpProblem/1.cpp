#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int countWays(int n) {
        // your code here
        int prev1 = 2;
        int prev2 = 1;
        for(int i=3; i<=n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

class Solution_Tabulation {
  public:
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

class Solution_Memoization {
  private:
    int countWays(int n, vector<int> &dp) {
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = countWays(n-1, dp) + countWays(n-2, dp);
    }
  
  public:
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, -1);
        countWays(n, dp);
        return dp[n];
    }
};


class Solution_Recursion {
  public:
    int countWays(int n) {
        // your code here
        if(n<=2) return n;
        return countWays(n-1) + countWays(n-2);
    }
};