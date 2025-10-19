#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        map<int, int> mp;
        int sum=0;
        int ans=0;
        mp[0]=1;
        for(auto it: arr) {
            sum += it;
            int req = sum-k;
            ans += mp[req];
            mp[sum]++;
        }
        return ans;
    }
};