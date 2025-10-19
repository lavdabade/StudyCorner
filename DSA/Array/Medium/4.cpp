#include<iostream>
#include<vector>

using namespace std;

// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        int currStart = 0;
        int ansStart = 0;
        int ansEnd = -1;
        int sumTillNow = 0;
        int maxSum = 0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] < 0) {
                currStart = i+1;
                sumTillNow = 0;
                continue;
            }
            sumTillNow += arr[i];
            if(maxSum <= sumTillNow) {
                ansStart = currStart;
                ansEnd = i;
                maxSum = sumTillNow;
            }
        }
        if(ansEnd == -1) return {-1};
        vector<int> ans;
        for(int i=ansStart; i<=ansEnd; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};