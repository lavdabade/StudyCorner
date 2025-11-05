#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int numberofLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> lisSize(n, 1);
        vector<int> lisCnt(n, 1);
        int ans = 0;
        int maxLis = 0;
        for(int idx=0; idx<n; idx++) {
            for(int prevIdx=0; prevIdx<idx; prevIdx++) {
                if(arr[prevIdx] < arr[idx]) {
                    if(lisSize[prevIdx] + 1 == lisSize[idx]) {
                        lisCnt[idx] += lisCnt[prevIdx];
                    }
                    else if(lisSize[prevIdx] + 1 > lisSize[idx]) {
                        lisSize[idx] = lisSize[prevIdx] + 1;
                        lisCnt[idx] = lisCnt[prevIdx];
                    }
                }
            }
            maxLis = max(maxLis, lisSize[idx]);
        }
        for(int idx=0; idx<n; idx++) {
            if(lisSize[idx] == maxLis) {
                ans += lisCnt[idx];
            }
        }
        return ans;
    }
};