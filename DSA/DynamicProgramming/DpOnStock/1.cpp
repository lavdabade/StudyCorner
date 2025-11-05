#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int minTillNow = prices[0];
        int ans = 0;
        for(auto it: prices) {
            ans = max(ans, it - minTillNow);
            minTillNow = min(minTillNow, it);
        }
        return ans;
    }
};