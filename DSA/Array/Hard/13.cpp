#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int pre = 1;
        int suf = 1;
        int ans = arr[0];
        for(int i=0; i<n; i++) {
            pre *= arr[i];
            suf *= arr[n-i-1];
            ans = max(ans, pre);
            ans = max(ans, suf);
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
        }
        return ans;
    }
};