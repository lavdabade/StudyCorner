#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int left = 0;
        int right = arr.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(arr[mid] >= target) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};