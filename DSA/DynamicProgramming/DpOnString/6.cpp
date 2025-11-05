#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
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
        return ((n-prev[0]) + (m-prev[0]));
    }
};



class Solution_Tabulation {
  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i1=n-1; i1>=0; i1--) {
            for(int i2=m-1; i2>=0; i2--) {
                if(s1[i1] == s2[i2]) dp[i1][i2] = 1 + dp[i1+1][i2+1];
                else dp[i1][i2] = max(dp[i1+1][i2], dp[i1][i2+1]);
            }
        }
        return ((n-dp[0][0]) + (m-dp[0][0]));
    }
};