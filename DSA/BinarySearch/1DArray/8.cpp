#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    int getFirstIndex(vector<int> &arr, int target) {
        int left = 0;
        int right = arr.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(arr[mid] >= target) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
    
    int getLastIndex(vector<int> &arr, int target) {
        int left = 0;
        int right = arr.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(arr[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return right;
    }
  
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int firstIdx = getFirstIndex(arr, target);
        if(firstIdx == arr.size() || arr[firstIdx]!=target) return 0;
        int lastIdx = getLastIndex(arr, target);
        return lastIdx - firstIdx + 1;
    }
};
