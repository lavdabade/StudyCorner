#include<iostream>
#include<vector>

using namespace std;

class Solution {
    vector<int> divisibleSet(vector<int> &arr)
    {
        // Write your code here.
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int maxIdx = 0;
        vector<int> lisSize(n, 1);
        vector<int> parent(n);
        for(int idx=0; idx<n; idx++) {
            parent[idx] = idx;
            for(int prevIdx=0; prevIdx<idx; prevIdx++) {
                if((arr[idx]%arr[prevIdx] == 0) && (lisSize[prevIdx] + 1 > lisSize[idx])) {
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