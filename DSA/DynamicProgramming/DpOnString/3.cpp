#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i1=n-1; i1>=0; i1--) {
            for(int i2=m-1; i2>=0; i2--) {
                if(s1[i1] == s2[i2]) {
                    dp[i1][i2] = 1 + dp[i1+1][i2+1];
                }
                ans = max(ans, dp[i1][i2]);
            }
        }
        return ans;
    }
};



class Solution_Recursion {
  private:
    void longestCommonSubstrUtil(int i1, int i2, int currLen, int &ans, int n, int m, string &s1, string &s2) {
        if(i1 == n || i2 == m) return;
        if(s1[i1] == s2[i2]) {
            ans = max(ans, currLen+1);
            longestCommonSubstrUtil(i1+1, i2+1, currLen+1, ans, n, m, s1, s2);
        }
        longestCommonSubstrUtil(i1, i2+1, 0, ans, n, m, s1, s2);
        longestCommonSubstrUtil(i1+1, i2, 0, ans, n, m, s1, s2);
    }
    
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        int ans = 0;
        longestCommonSubstrUtil(0, 0, 0, ans, n, m, s1, s2);
        return ans;
    }
};