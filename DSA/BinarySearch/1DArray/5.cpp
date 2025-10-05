#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        if(arr[0] > x) return -1;
        int left = 0;
        int right = arr.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(arr[mid] <= x) left = mid+1;
            else right = mid-1;
        }
        return right;
    }
};