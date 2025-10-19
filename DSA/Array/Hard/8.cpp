#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>> ans;
        int i = 0;
        if(newInterval[1] < intervals[0][0]) ans.push_back(newInterval);
        while(i < intervals.size()) {
            if(newInterval[0] > intervals[i][1] || newInterval[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
                i++;
            }
            else {
                int newStart = newInterval[0];
                int newEnd = newInterval[1];
                while(i < intervals.size() && newInterval[0] <= intervals[i][1] && newInterval[1] >= intervals[i][0]) {
                    newStart = min(newStart, intervals[i][0]);
                    newEnd = max(newEnd, intervals[i][1]);
                    i++;
                }
                ans.push_back({newStart, newEnd});
            }
        }
        if(newInterval[0] > intervals.back()[1]) ans.push_back(newInterval);
        return ans;
    }
};