#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int ans = 0;
        map<int, int> mp;
        int sum = 0;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            sum += arr[i];
            if(sum==0) {
                ans = i+1;
                continue;
            }
            if(mp.find(sum) != mp.end()) 
                ans = max(ans, i-mp[sum]);
            else 
                mp[sum] = i;
        }
        return ans;
    }
};