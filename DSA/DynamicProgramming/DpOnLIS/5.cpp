#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> forward(n, 1);
        vector<int> backword(n, 1);
        for(int idx=1; idx<n; idx++) {
            for(int prevIdx=0; prevIdx<idx; prevIdx++) {
                if(nums[prevIdx]<nums[idx] && forward[prevIdx]+1 > forward[idx]) {
                    forward[idx] = forward[prevIdx] + 1;
                }
            }
        }
        for(int idx=n-2; idx>=0; idx--) {
            for(int prevIdx=n-1; prevIdx>idx; prevIdx--) {
                if(nums[prevIdx]<nums[idx] && backword[prevIdx]+1 > backword[idx]) {
                    backword[idx] = backword[prevIdx] + 1;
                }
            }
        }
        int ans = 0;
        for(int i1=0; i1<n; i1++) {
            if(forward[i1] != 1 && backword[i1] != 1) ans = max(ans, forward[i1]+backword[i1]-1);
        }
        return ans;
    }
};