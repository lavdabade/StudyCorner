#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

class Solution {
  private:
    int getNoOfSubArray(vector<int> &arr, int limit) {
        int noOfSubArray = 0;
        int currSum = 0;
        for(auto it: arr) {
            if(currSum + it <= limit) {
                currSum += it;
            }
            else {
                noOfSubArray++;
                currSum = it;
            }
        }
        return noOfSubArray+1;
    }
    
  public:
    int splitArray(vector<int>& arr, int k) {
        // code here
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);
        while(left <= right) {
            int mid = left + (right-left)/2;
            int noOfSubArray = getNoOfSubArray(arr, mid);
            if(noOfSubArray > k) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};