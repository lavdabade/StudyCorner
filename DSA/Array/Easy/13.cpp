#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int ans = 0;
        int zeroLen = 0;
        int oneLen = 0;
        for(auto it: arr) {
            if(it==0) {
                ans = max(ans, oneLen);
                oneLen = 0;
                zeroLen++;
            }
            else {
                ans = max(ans, zeroLen);
                zeroLen = 0;
                oneLen++;
            }
        }
        ans = max(ans, zeroLen);
        ans = max(ans, oneLen);
        return ans;
    }
};