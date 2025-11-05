#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int cutsSize = cuts.size();
        vector<vector<int>> dp(cutsSize, vector<int>(cutsSize, 0));
        for(int start=cutsSize-1; start>=1; start--) {
            for(int end=start; end<cutsSize-1; end++) {
                int ans = INT_MAX;
                for(int k=start; k<=end; k++) {
                    int curr = cuts[end+1] - cuts[start-1] 
                            + dp[start][k-1]
                            + dp[k+1][end];
                    ans = min(ans, curr);
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][cutsSize-2];
    }
};



class Solution_Memoization {
private:
    int minCostUtil(int start, int end, vector<int> &cuts, vector<vector<int>> &dp) {
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        for(int k=start; k<=end; k++) {
            int curr = cuts[end+1] - cuts[start-1] 
                     + minCostUtil(start, k-1, cuts, dp)
                     + minCostUtil(k+1, end, cuts, dp);
            ans = min(ans, curr);
        }
        return dp[start][end] = ans;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int cutsSize = cuts.size();
        vector<vector<int>> dp(cutsSize, vector<int>(cutsSize, -1));
        return minCostUtil(1, cutsSize-2, cuts, dp);
    }
};



class Solution_Recursion {
private:
    int minCostUtil(int start, int end, vector<int> &cuts) {
        if(start > end) return 0;
        int ans = INT_MAX;
        for(int k=start; k<=end; k++) {
            int curr = cuts[end+1] - cuts[start-1] 
                     + minCostUtil(start, k-1, cuts)
                     + minCostUtil(k+1, end, cuts);
            ans = min(ans, curr);
        }
        return ans;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return minCostUtil(1, cuts.size()-2, cuts);
    }
};