#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int ans = 0;
        int n = arr.size();
        vector<int> lisSize(n, 1);
        vector<int> parent(n);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        for(int idx=1; idx<n; idx++) {
            for(int prevIdx=0; prevIdx<idx; prevIdx++) {
                if(arr[prevIdx] < arr[idx] && (lisSize[prevIdx] + 1 > lisSize[idx])) {
                    lisSize[idx] = lisSize[prevIdx] + 1;
                    parent[idx] = prevIdx;
                    ans = max(ans, lisSize[idx]);
                }
            }
        }
        return ans;
    }
};



class Solution_Space_Optimized {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> prev(n+1, 0);
        for(int idx=n-1; idx>=0; idx--) {
            vector<int> curr(n+1, 0);
            for(int prevIdx=idx-1; prevIdx>=-1; prevIdx--) {
                int take = 0;
                if(prevIdx == -1 || arr[idx] > arr[prevIdx]) {
                    take = 1 + prev[idx+1];
                }
                int notTake = prev[prevIdx+1];
                curr[prevIdx+1] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[-1+1];
    }
};



class Solution_Tabulation {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int idx=n-1; idx>=0; idx--) {
            for(int prevIdx=idx-1; prevIdx>=-1; prevIdx--) {
                int take = 0;
                if(prevIdx == -1 || arr[idx] > arr[prevIdx]) {
                    take = 1 + dp[idx+1][idx+1];
                }
                int notTake = dp[idx+1][prevIdx+1];
                dp[idx][prevIdx+1] = max(take, notTake);
            }
        }
        return dp[0][-1+1];
    }
};



class Solution_Memoization {
  private:
    int lisUtil(int idx, int prevIdx, int n, vector<int> &arr, vector<vector<int>> &dp) {
        if(idx == n) return 0;
        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];
        int take = 0;
        if(prevIdx == -1 || arr[idx] > arr[prevIdx]) {
            take = 1 + lisUtil(idx+1, idx, n, arr, dp);
        }
        int notTake = lisUtil(idx+1, prevIdx, n, arr, dp);
        return dp[idx][prevIdx+1] = max(take, notTake);
    }
    
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return lisUtil(0, -1, n, arr, dp);
    }
};



class Solution_Recursion {
  private:
    int lisUtil(int idx, int prevIdx, int n, vector<int> &arr) {
        if(idx == n) return 0;
        int take = 0;
        if(prevIdx == -1 || arr[idx] > arr[prevIdx]) {
            take = 1 + lisUtil(idx+1, idx, n, arr);
        }
        int notTake = lisUtil(idx+1, prevIdx, n, arr);
        return max(take, notTake);
    }
    
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        return lisUtil(0, -1, n, arr);
    }
};