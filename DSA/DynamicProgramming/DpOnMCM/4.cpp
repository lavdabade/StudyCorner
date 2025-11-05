#include<iostream>
#include<vector>

using namespace std;

// User function Template for C++
class Solution {
  public:
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        for(int i=0; i<n; i++) {
            if(s[i] == 'T') {
                dp[i][i][1] = 1;
            }
            else {
                dp[i][i][0] = 1;
            }
        }
        for(int start=n-1; start>=0; start=start-2) {
            for(int end=start+2; end<n; end=end+2) {
                for(int isTrue=0; isTrue<=1; isTrue++) {
                    int ans = 0;
                    for(int k=start+1; k<end; k+=2) {
                        int lt = dp[start][k-1][1];
                        int lf = dp[start][k-1][0];
                        int rt = dp[k+1][end][1];
                        int rf = dp[k+1][end][0];
                        if(s[k] == '&') {
                            if(isTrue) ans = ans + lt*rt;
                            else ans = ans + lt*rf + lf*rf + lf*rt;
                        }
                        else if(s[k] == '|') {
                            if(isTrue) ans = ans + lt*rf + lt*rt + lf*rt;
                            else ans = ans + lf*rf;
                        }
                        else {
                            if(isTrue) ans = ans + lf*rt + lt*rf;
                            else ans = ans + lt*rt + lf*rf;
                        }
                    }
                    dp[start][end][isTrue] = ans;
                }
            }
        }
        return dp[0][n-1][1];
    }
};



// User function Template for C++
class Solution_Memoization {
  private:
    int countWaysUtil(int start, int end, int isTrue, string &s, vector<vector<vector<int>>> &dp) {
        if(dp[start][end][isTrue] != -1) return dp[start][end][isTrue];
        if(start == end) {
            if(isTrue) return dp[start][end][isTrue] = (s[start] == 'T' ? 1 : 0);
            else return dp[start][end][isTrue] = (s[start] == 'F' ? 1 : 0);
        } 
        int ans = 0;
        for(int k=start+1; k<end; k+=2) {
            int lt = countWaysUtil(start, k-1, 1, s, dp);
            int lf = countWaysUtil(start, k-1, 0, s, dp);
            int rt = countWaysUtil(k+1, end, 1, s, dp);
            int rf = countWaysUtil(k+1, end, 0, s, dp);
            if(s[k] == '&') {
                if(isTrue) ans = ans + lt*rt;
                else ans = ans + lt*rf + lf*rf + lf*rt;
            }
            else if(s[k] == '|') {
                if(isTrue) ans = ans + lt*rf + lt*rt + lf*rt;
                else ans = ans + lf*rf;
            }
            else {
                if(isTrue) ans = ans + lf*rt + lt*rf;
                else ans = ans + lt*rt + lf*rf;
            }
        }
        return dp[start][end][isTrue] = ans;
    }
    
  public:
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return countWaysUtil(0, n-1, 1, s, dp);
    }
};



// User function Template for C++
class Solution_Recursion {
  private:
    int countWaysUtil(int start, int end, int isTrue, string &s) {
        if(start == end) {
            if(isTrue) return (s[start] == 'T' ? 1 : 0);
            else return (s[start] == 'F' ? 1 : 0);
        } 
        int ans = 0;
        for(int k=start+1; k<end; k+=2) {
            int lt = countWaysUtil(start, k-1, 1, s);
            int lf = countWaysUtil(start, k-1, 0, s);
            int rt = countWaysUtil(k+1, end, 1, s);
            int rf = countWaysUtil(k+1, end, 0, s);
            if(s[k] == '&') {
                if(isTrue) ans = ans + lt*rt;
                else ans = ans + lt*rf + lf*rf + lf*rt;
            }
            else if(s[k] == '|') {
                if(isTrue) ans = ans + lt*rf + lt*rt + lf*rt;
                else ans = ans + lf*rf;
            }
            else {
                if(isTrue) ans = ans + lf*rt + lt*rf;
                else ans = ans + lt*rt + lf*rf;
            }
        }
        return ans;
    }
    
  public:
    int countWays(string &s) {
        // code here
        int n = s.size();
        return countWaysUtil(0, n-1, 1, s);
    }
};