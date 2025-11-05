#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
  public:
    string findLCS(int n, int m,string &s1, string &s2){
        // Write your code here.
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i1=n-1; i1>=0; i1--) {
            for(int i2=m-1; i2>=0; i2--) {
                if(s1[i1] == s2[i2]) dp[i1][i2] = 1 + dp[i1+1][i2+1];
                else dp[i1][i2] = max(dp[i1+1][i2], dp[i1][i2+1]);
            }
        }
        string ans = "";
        int i1 = 0;
        int i2 = 0;
        while(i1<n && i2<m) {
            if(s1[i1] == s2[i2]) {
                ans.push_back(s1[i1]);
                i1++;
                i2++;
            }
            else {
                if(dp[i1+1][i2] > dp[i1][i2+1]) {
                    i1++;
                }
                else {
                    i2++;
                }
            }
        }
        return ans;
    }
};


class Solution_Memoization {
  private:
    int findLCSUtil(int i1, int i2, int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i1 == n || i2 == m) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s1[i1] == s2[i2]) return dp[i1][i2] = 1 + findLCSUtil(i1+1, i2+1, n, m, s1, s2, dp);
        else return dp[i1][i2] = max(findLCSUtil(i1+1, i2, n, m, s1, s2, dp), findLCSUtil(i1, i2+1, n, m, s1, s2, dp));
    }

  public:
    string findLCS(int n, int m,string &s1, string &s2){
        // Write your code here.
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        findLCSUtil(0, 0, n, m, s1, s2, dp);
        string ans = "";
        int i1 = 0;
        int i2 = 0;
        while(i1<n && i2<m) {
            if(s1[i1] == s2[i2]) {
                ans.push_back(s1[i1]);
                i1++;
                i2++;
            }
            else {
                if(dp[i1+1][i2] > dp[i1][i2+1]) {
                    i1++;
                }
                else {
                    i2++;
                }
            }
        }
        return ans;
    }
};