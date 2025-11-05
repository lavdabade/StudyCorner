#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maxSkill(vector<int> &arr) {
        // code here
        int n = arr.size();
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int start=n+1; start>=1; start--) {
            for(int end=start; end<=n; end++) {
                int ans = 0;
                for(int k=start; k<=end; k++) {
                    int curr = arr[start-1]*arr[k]*arr[end+1]
                             + dp[start][k-1]
                             + dp[k+1][end];
                    ans = max(ans, curr);
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }
};



class Solution_Memoization {
  private:
    int maxSkillUtil(int start, int end, vector<int> &arr, vector<vector<int>> &dp) {
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = 0;
        for(int k=start; k<=end; k++) {
            int curr = arr[start-1]*arr[k]*arr[end+1]
                     + maxSkillUtil(start, k-1, arr, dp)
                     + maxSkillUtil(k+1, end, arr, dp);
            ans = max(ans, curr);
        }
        return dp[start][end] = ans;
    }
    
  public:
    int maxSkill(vector<int> &arr) {
        // code here
        int n = arr.size();
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return maxSkillUtil(1, n, arr, dp);
    }
};



class Solution_Recursion {
  private:
    int maxSkillUtil(int start, int end, vector<int> &arr) {
        if(start > end) return 0;
        int ans = 0;
        for(int k=start; k<=end; k++) {
            int curr = arr[start-1]*arr[k]*arr[end+1]
                     + maxSkillUtil(start, k-1, arr)
                     + maxSkillUtil(k+1, end, arr);
            ans = max(ans, curr);
        }
        return ans;
    }
    
  public:
    int maxSkill(vector<int> &arr) {
        // code here
        int n = arr.size();
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        return maxSkillUtil(1, n, arr);
    }
};