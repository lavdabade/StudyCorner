#include<iostream>
#include<vector>

using namespace std;

// User function Template for C++
class Solution {
  public:
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        // code here
        vector<vector<int>> dp = matrix;
        for(int i=1; i<N; i++) {
            for(int j=1; j<M; j++) {
                if(dp[i][j] == 1) {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }
            }
        }
        int ans = 0;
        for(auto it: dp) {
            for(auto itt: it) {
                ans += itt;
            }
        }
        return ans;
    }
};