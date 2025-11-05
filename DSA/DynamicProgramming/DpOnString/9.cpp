#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
  private:
    const int MOD = 1e9 + 7;

  public:
    int distinctSubsequences(string &str, string &sub)
    {
        // Write your code here.
        int n = str.size();
        int m = sub.size();
        vector<int> prev(m+1, 0);
        prev[m] = 1;
        for(int i1=n-1; i1>=0; i1--) {
            vector<int> curr(m+1, 0);
            curr[m] = 1;
            for(int i2=m-1; i2>=0; i2--) {
                int ans = 0;
                if(str[i1] == sub[i2]) ans = prev[i2+1];
                ans = (ans + prev[i2])%MOD;
                curr[i2] = ans;
            }
            prev = curr;
        }
        return prev[0];
    }
};



class Solution_Tabulation {
  private:
    const int MOD = 1e9 + 7;

  public:
    int distinctSubsequences(string &str, string &sub)
    {
        // Write your code here.
        int n = str.size();
        int m = sub.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i1=0; i1<=n; i1++) {
            dp[i1][m] = 1;
        }
        for(int i1=n-1; i1>=0; i1--) {
            for(int i2=m-1; i2>=0; i2--) {
                int ans = 0;
                if(str[i1] == sub[i2]) ans = dp[i1+1][i2+1];
                ans = (ans + dp[i1+1][i2])%MOD;
                dp[i1][i2] = ans;
            }
        }
        return dp[0][0];
    }
};

class Solution_Memoization {
  private:
    const int MOD = 1e9 + 7;
    int distinctSubsequencesUtil(int i1, int i2, int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i2 == m) return 1;
        if(i1 == n) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        int ans = 0;
        if(s1[i1] == s2[i2]) ans = distinctSubsequencesUtil(i1+1, i2+1, n, m, s1, s2, dp);
        ans = (ans + distinctSubsequencesUtil(i1+1, i2, n, m, s1, s2, dp))%MOD;
        return dp[i1][i2] = ans;
    }

  public:
    int distinctSubsequences(string &str, string &sub)
    {
        // Write your code here.
        int n = str.size();
        int m = sub.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return distinctSubsequencesUtil(0, 0, n, m, str, sub, dp);
    }
};

class Solution_Recursion {
  private:
    const int MOD = 1e9 + 7;
    int distinctSubsequencesUtil(int i1, int i2, int n, int m, string &s1, string &s2) {
        if(i2 == m) return 1;
        if(i1 == n) return 0;
        int ans = 0;
        if(s1[i1] == s2[i2]) ans = distinctSubsequencesUtil(i1+1, i2+1, n, m, s1, s2);
        ans = (ans + distinctSubsequencesUtil(i1+1, i2, n, m, s1, s2))%MOD;
        return ans;
    }

  public:
    int distinctSubsequences(string &str, string &sub)
    {
        // Write your code here.
        int n = str.size();
        int m = sub.size();
        return distinctSubsequencesUtil(0, 0, n, m, str, sub);
    }
};