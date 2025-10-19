#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        map<int, int> mp;
        int xr = 0;
        long ans = 0;
        mp[0] = 1;
        for(auto it: arr) {
            xr ^= it;
            int req = xr ^ k;
            ans += mp[req];
            mp[xr]++;
        }
        return ans;
    }
};