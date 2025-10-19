#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum=0;
        int ans=0;
        map<int, int> mp;
        for(int i=0; i<arr.size(); i++) {
            sum+=arr[i];
            if(sum==k) {
                ans=i+1;
                continue;
            }
            int req = sum - k;
            if(mp.find(req)!=mp.end() && ans < (i-mp[req])) {
                ans = i-mp[req];
            }
            if(mp.find(sum)==mp.end()) {
                mp[sum]=i;
            }
        }
        return ans;
    }
};