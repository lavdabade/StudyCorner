#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
  public:
    int findMinInsertions(string &s) {
        // code here
        int n = s.size();
        string r = s;
        reverse(r.begin(), r.end());
        vector<int> prev(n+1, 0);
        for(int i1=n-1; i1>=0; i1--) {
            vector<int> curr(n+1, 0);
            for(int i2=n-1; i2>=0; i2--) {
                if(s[i1] == r[i2]) curr[i2] = 1 + prev[i2+1];
                else curr[i2] = max(prev[i2], curr[i2+1]);
            }
            prev = curr;
        }
        return n - prev[0];
    }
};



class Solution_Tabulation {
  public:
    int findMinInsertions(string &s) {
        // code here
        int n = s.size();
        string r = s;
        reverse(r.begin(), r.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i1=n-1; i1>=0; i1--) {
            for(int i2=n-1; i2>=0; i2--) {
                if(s[i1] == r[i2]) dp[i1][i2] = 1 + dp[i1+1][i2+1];
                else dp[i1][i2] = max(dp[i1+1][i2], dp[i1][i2+1]);
            }
        }
        return n - dp[0][0];
    }
};