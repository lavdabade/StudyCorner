#include<istream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for(int start=n-1; start>=0; start--) {
            int maxElement = arr[start];
            int ans = 0;
            for(int i=start, _k=0; i<n && _k<k; i++, _k++) {
                maxElement=max(maxElement, arr[i]);
                ans = max(ans, maxElement*(i-start+1) + dp[i+1]);
            }
            dp[start] = ans;
        }
        return dp[0];
    }
};



class Solution_Memoization {
private:
    int maxSumAfterPartitioningUtil(int start, int n, int k, vector<int> &arr, vector<int> &dp) {
        if(start == n) return 0;
        if(dp[start] != -1) return dp[start];
        int maxElement = arr[start];
        int ans = 0;
        for(int i=start, _k=0; i<n && _k<k; i++, _k++) {
            maxElement=max(maxElement, arr[i]);
            ans = max(ans, maxElement*(i-start+1) + maxSumAfterPartitioningUtil(i+1, n, k, arr, dp));
        }
        return dp[start] = ans;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return maxSumAfterPartitioningUtil(0, n, k, arr, dp);
    }
};



class Solution_Recursion {
private:
    int maxSumAfterPartitioningUtil(int start, int n, int k, vector<int> &arr) {
        if(start == n) return 0;
        int maxElement = arr[start];
        int ans = 0;
        for(int i=start, _k=0; i<n && _k<k; i++, _k++) {
            maxElement=max(maxElement, arr[i]);
            ans = max(ans, maxElement*(i-start+1) + maxSumAfterPartitioningUtil(i+1, n, k, arr));
        }
        return ans;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return maxSumAfterPartitioningUtil(0, n, k, arr);
    }
};