#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int findMin(int n) {
        // code here
        int ans = 0;
        vector<int> coins = {1, 2, 5, 10};
        for(int idx=coins.size()-1; idx>=0; idx--) {
            ans += (n/coins[idx]);
            n %= coins[idx];
        }
        return ans;
    }
};