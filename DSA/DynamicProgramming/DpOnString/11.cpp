#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
  private:
    bool isAllStarInPattern(int idx, int m, string &pat) {
        while(idx<m) {
            if(pat[idx] != '*') {
                return false;
            }
            idx++;
        }
        return true;
    }
    
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size();
        int m = pat.size();
        vector<int> prev(m+1, 0);
        for(int i2=0; i2<=m; i2++) {
            prev[i2] = isAllStarInPattern(i2, m, pat);
        }
        for(int i1=n-1; i1>=0; i1--) {
            vector<int> curr(m+1, 0);
            for(int i2=m-1; i2>=0; i2--) {
                if(txt[i1] == pat[i2] || pat[i2] == '?') curr[i2] = prev[i2+1];
                else if(pat[i2] == '*') curr[i2] = (prev[i2] || curr[i2+1]);
            }
            prev = curr;
        }
        return prev[0];
    }
};


class Solution_Tabulation {
  private:
    bool isAllStarInPattern(int idx, int m, string &pat) {
        while(idx<m) {
            if(pat[idx] != '*') {
                return false;
            }
            idx++;
        }
        return true;
    }
    
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size();
        int m = pat.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i2=0; i2<=m; i2++) {
            dp[n][i2] = isAllStarInPattern(i2, m, pat);
        }
        for(int i1=n-1; i1>=0; i1--) {
            for(int i2=m-1; i2>=0; i2--) {
                if(txt[i1] == pat[i2] || pat[i2] == '?') dp[i1][i2] = dp[i1+1][i2+1];
                else if(pat[i2] == '*') dp[i1][i2] = (dp[i1+1][i2] || dp[i1][i2+1]);
            }
        }
        return dp[0][0];
    }
};


class Solution_Memoization {
  private:
    bool isAllStarInPattern(int idx, int m, string &pat) {
        while(idx<m) {
            if(pat[idx] != '*') {
                return false;
            }
            idx++;
        }
        return true;
    }
  
    bool wildCardUtil(int i1, int i2, int n, int m, string &txt, string &pat, vector<vector<int>> &dp) {
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(i1 == n) return dp[i1][i2] = isAllStarInPattern(i2, m, pat);
        if(i2 == m) return dp[i1][i2] = false;
        else if(txt[i1] == pat[i2] || pat[i2] == '?') return dp[i1][i2] = wildCardUtil(i1+1, i2+1, n, m, txt, pat, dp);
        else if(pat[i2] == '*') return dp[i1][i2] = (wildCardUtil(i1+1, i2, n, m, txt, pat, dp) || wildCardUtil(i1, i2+1, n, m, txt, pat, dp));
        else return dp[i1][i2] = false;
    }
    
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size();
        int m = pat.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return wildCardUtil(0, 0, n, m, txt, pat, dp);
    }
};



class Solution_Recursion {
  private:
    bool isAllStarInPattern(int idx, int m, string &pat) {
        while(idx<m) {
            if(pat[idx] != '*') {
                return false;
            }
            idx++;
        }
        return true;
    }
  
    bool wildCardUtil(int i1, int i2, int n, int m, string &txt, string &pat) {
        if(i1 == n) return isAllStarInPattern(i2, m, pat);
        if(i2 == m) return false;
        else if(txt[i1] == pat[i2] || pat[i2] == '?') return wildCardUtil(i1+1, i2+1, n, m, txt, pat);
        else if(pat[i2] == '*') return (wildCardUtil(i1+1, i2, n, m, txt, pat) || wildCardUtil(i1, i2+1, n, m, txt, pat));
        else return false;
    }
    
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size();
        int m = pat.size();
        return wildCardUtil(0, 0, n, m, txt, pat);
    }
};