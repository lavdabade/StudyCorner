#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        for(int i=1; i<arr.size(); i++) {
            int prevEnd = ans.back()[1];
            int currStart = arr[i][0];
            int currEnd = arr[i][1];
            if(currStart <= prevEnd) ans.back()[1] = max(ans.back()[1], currEnd);
            else ans.push_back(arr[i]);
        }
        return ans;
    }
};