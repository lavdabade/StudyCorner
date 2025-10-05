#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int minNumber(int arr[], int low, int high) {
        // Your code here
        int mini=arr[low];
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(arr[low]<=arr[mid]) {
                mini=min(mini, arr[low]);
                low=mid+1;
            }
            else {
                mini=min(mini, arr[mid]);
                high=mid-1;
            }
        }
        return mini;
    }
};