#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i1=n-1; i1>=0; i1--) {
            for(int i2=m-1; i2>=0; i2--) {
                if(s1[i1] == s2[i2]) dp[i1][i2] = 1 + dp[i1+1][i2+1];
                else dp[i1][i2] = max(dp[i1+1][i2], dp[i1][i2+1]);
            }
        }
        int i1 = 0;
        int i2 = 0;
        string ans = "";
        while(i1<n && i2<m) {
            if(s1[i1] == s2[i2]) {
                ans.push_back(s1[i1]);
                i1++;
                i2++;
            }
            else {
                if(dp[i1][i2+1] > dp[i1+1][i2]) {
                    ans.push_back(s2[i2]);
                    i2++;
                }
                else {
                    ans.push_back(s1[i1]);
                    i1++;
                }
            }
        }
        while(i1<n) {
            ans.push_back(s1[i1]);
            i1++;
        }
        while(i2<m) {
            ans.push_back(s2[i2]);
            i2++;
        }
        return ans;
    }
};