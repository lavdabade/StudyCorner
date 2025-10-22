#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

class Solution {
  private:
    int getNoOfPainter(vector<int> &arr, int capacity) {
        int noOfPainter = 0;
        int currCapacity = 0;
        for(auto it: arr) {
            if(currCapacity + it <= capacity) {
                currCapacity += it;
            }
            else {
                noOfPainter++;
                currCapacity = it;
            }
        }
        return noOfPainter+1;
    }
    
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);
        while(left <= right) {
            int mid = left + (right-left)/2;
            int noOfPainter = getNoOfPainter(arr, mid);
            if(noOfPainter > k) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return left;
    }
};