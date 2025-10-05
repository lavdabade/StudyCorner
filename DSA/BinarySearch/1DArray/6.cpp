#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        if(arr.back() < x) return -1;
        int left = 0;
        int right = arr.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(arr[mid] >= x) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};