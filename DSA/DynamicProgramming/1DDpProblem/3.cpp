#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, 0);
        for(int idx=n-2; idx>=0; idx--) {
            int ans = INT_MAX;
            for(int i=idx+1; i<=min(n-1, idx+k); i++) {
                ans = min(ans, abs(heights[idx] - heights[i]) + dp[i]);
            }
            dp[idx] = ans;
        }
        return dp[0];
    }
};



class Solution_Memoization {
private:
    int frogJumpUtil(int idx, int k, int n, vector<int> &heights, vector<int> &dp) {
        if(idx == n-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int ans = INT_MAX;
        for(int i=idx+1; i<=min(n-1, idx+k); i++) {
            ans = min(ans, abs(heights[idx] - heights[i]) + frogJumpUtil(i, k, n, heights, dp));
        }
        return dp[idx] = ans;
    }

public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n-1, -1);
        return frogJumpUtil(0, k, n, heights, dp);
    }
};



class Solution_Recursion {
private:
    int frogJumpUtil(int idx, int k, int n, vector<int> &heights) {
        if(idx == n-1) return 0;
        int ans = INT_MAX;
        for(int i=idx+1; i<=min(n-1, idx+k); i++) {
            ans = min(ans, abs(heights[idx] - heights[i]) + frogJumpUtil(i, k, n, heights));
        }
        return ans;
    }

public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return frogJumpUtil(0, k, n, heights);
    }
};