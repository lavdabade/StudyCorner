#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<int> prev(4);
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        for(int idx=1; idx<n; idx++) {
            vector<int> curr(4);
            for(int prevIdx=0; prevIdx<4; prevIdx++) {
                int ans = INT_MIN;
                for(int i=0; i<3; i++) {
                    if(i!=prevIdx) {
                        ans = max(ans, arr[idx][i] + prev[i]);
                    }
                }
                curr[prevIdx] = ans;
            }
            prev = curr;
        }
        return prev[3];
    }
};



class Solution_Tabulation {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4));
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        for(int idx=1; idx<n; idx++) {
            for(int prevIdx=0; prevIdx<4; prevIdx++) {
                int ans = INT_MIN;
                for(int i=0; i<3; i++) {
                    if(i!=prevIdx) {
                        ans = max(ans, arr[idx][i] + dp[idx-1][i]);
                    }
                }
                dp[idx][prevIdx] = ans;
            }
        }
        return dp[n-1][3];
    }
};



class Solution_Memoization {
  private:
    int maximumPointsUtil(int idx, int prevIdx, vector<vector<int>> &arr, vector<vector<int>> &dp) {
        if(idx == 0) {
            int ans = INT_MIN;
            for(int i=0; i<3; i++) {
                if(i!=prevIdx) {
                    ans = max(ans, arr[idx][i]);
                }
            }
            return ans;
        }
        if(dp[idx][prevIdx]!=-1) return dp[idx][prevIdx];
        int ans = INT_MIN;
        for(int i=0; i<3; i++) {
            if(i!=prevIdx) {
                ans = max(ans, arr[idx][i] + maximumPointsUtil(idx-1, i, arr, dp));
            }
        }
        return dp[idx][prevIdx] = ans;
    }
    
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return maximumPointsUtil(n-1, 3, arr, dp);
    }
};



class Solution_Recursion {
  private:
    int maximumPointsUtil(int idx, int prevIdx, vector<vector<int>> &arr) {
        if(idx == 0) {
            int ans = INT_MIN;
            for(int i=0; i<3; i++) {
                if(i!=prevIdx) {
                    ans = max(ans, arr[idx][i]);
                }
            }
            return ans;
        }
        int ans = INT_MIN;
        for(int i=0; i<3; i++) {
            if(i!=prevIdx) {
                ans = max(ans, arr[idx][i] + maximumPointsUtil(idx-1, i, arr));
            }
        }
        return ans;
    }
    
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        return maximumPointsUtil(n-1, 3, arr);
    }
};