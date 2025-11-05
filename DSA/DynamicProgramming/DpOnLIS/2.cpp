#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> lisSize(n, 1);
        vector<int> parent(n);
        int maxIdx = 0;
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        for(int idx=1; idx<n; idx++) {
            for(int prevIdx=0; prevIdx<idx; prevIdx++) {
                if(arr[prevIdx] < arr[idx] && lisSize[prevIdx] + 1 > lisSize[idx]) {
                    lisSize[idx] = lisSize[prevIdx] + 1;
                    parent[idx] = prevIdx;
                    if(lisSize[maxIdx] < lisSize[idx]) {
                        maxIdx = idx;
                    }
                }
            }
        }
        vector<int> ans;
        while(parent[maxIdx] != maxIdx) {
            ans.push_back(arr[maxIdx]);
            maxIdx = parent[maxIdx];
        }
        ans.push_back(arr[maxIdx]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};