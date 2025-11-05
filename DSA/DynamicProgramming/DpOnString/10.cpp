#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m+1);
        for(int i2=0; i2<=m; i2++) {
            prev[i2] = m-i2;
        }
        for(int i1=n-1; i1>=0; i1--) {
            vector<int> curr(m+1);
            curr[m] = n-i1;
            for(int i2=m-1; i2>=0; i2--) {
                if(s1[i1] == s2[i2]) curr[i2] = prev[i2+1];
                else curr[i2] = (1 + min(prev[i2], min(prev[i2+1], curr[i2+1])));
            }
            prev = curr;
        }
        return prev[0];
    }
};



class Solution_Tabulation {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i1=0; i1<=n; i1++) {
            dp[i1][m] = n-i1;
        }
        for(int i2=0; i2<=m; i2++) {
            dp[n][i2] = m-i2;
        }
        for(int i1=n-1; i1>=0; i1--) {
            for(int i2=m-1; i2>=0; i2--) {
                if(s1[i1] == s2[i2]) dp[i1][i2] = dp[i1+1][i2+1];
                else dp[i1][i2] = (1 + min(dp[i1+1][i2], min(dp[i1+1][i2+1], dp[i1][i2+1])));
            }
        }
        return dp[0][0];
    }
};



class Solution_Memoization {
  private:
    int editDistanceUtil(int i1, int i2, int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i1 == n) return m-i2;
        if(i2 == m) return n-i1;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s1[i1] == s2[i2]) return dp[i1][i2] = editDistanceUtil(i1+1, i2+1, n, m, s1, s2, dp);
        else return dp[i1][i2] = (1 + min(editDistanceUtil(i1+1, i2, n, m, s1, s2, dp), min(editDistanceUtil(i1+1, i2+1, n, m, s1, s2, dp), editDistanceUtil(i1, i2+1, n, m, s1, s2, dp))));
    }
    
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return editDistanceUtil(0, 0, n, m, s1, s2, dp);
    }
};



class Solution_Recursion {
  private:
    int editDistanceUtil(int i1, int i2, int n, int m, string &s1, string &s2) {
        if(i1 == n) return m-i2;
        if(i2 == m) return n-i1;
        if(s1[i1] == s2[i2]) return editDistanceUtil(i1+1, i2+1, n, m, s1, s2);
        else return 1 + min(editDistanceUtil(i1+1, i2, n, m, s1, s2), min(editDistanceUtil(i1+1, i2+1, n, m, s1, s2), editDistanceUtil(i1, i2+1, n, m, s1, s2)));
    }
    
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        return editDistanceUtil(0, 0, n, m, s1, s2);
    }
};