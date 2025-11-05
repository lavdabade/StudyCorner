#include<iostream>
#include<string>

using namespace std;

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m+1, 0);
        for(int i1=n-1; i1>=0; i1--) {
            vector<int> curr(m+1, 0);
            for(int i2=m-1; i2>=0; i2--) {
                if(s1[i1] == s2[i2]) curr[i2] = 1 + prev[i2+1];
                else curr[i2] = max(prev[i2], curr[i2+1]);
            }
            prev = curr;
        }
        return prev[0];
    }
};



class Solution_Tabulation {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i1=n-1; i1>=0; i1--) {
            for(int i2=m-1; i2>=0; i2--) {
                if(s1[i1] == s2[i2]) dp[i1][i2] = 1 + dp[i1+1][i2+1];
                else dp[i1][i2] = max(dp[i1+1][i2], dp[i1][i2+1]);
            }
        }
        return dp[0][0];
    }
};



class Solution_Memoization {
  private:
    int lcsUtil(int i1, int i2, int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i1 == n || i2 == m) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s1[i1] == s2[i2]) return dp[i1][i2] = 1 + lcsUtil(i1+1, i2+1, n, m, s1, s2, dp);
        else return dp[i1][i2] = max(lcsUtil(i1+1, i2, n, m, s1, s2, dp), lcsUtil(i1, i2+1, n, m, s1, s2, dp));
    }
    
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return lcsUtil(0, 0, n, m, s1, s2, dp);
    }
};



class Solution_Recursion {
  private:
    int lcsUtil(int i1, int i2, int n, int m, string &s1, string &s2) {
        if(i1 == n || i2 == m) return 0;
        if(s1[i1] == s2[i2]) return 1 + lcsUtil(i1+1, i2+1, n, m, s1, s2);
        else return max(lcsUtil(i1+1, i2, n, m, s1, s2), lcsUtil(i1, i2+1, n, m, s1, s2));
    }
    
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        return lcsUtil(0, 0, n, m, s1, s2);
    }
};