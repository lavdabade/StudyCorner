#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int left=0;
        int right=arr.size()-1;
        int minIdx=0;
        while(left<=right) {
            int mid=left+(right-left)/2;
            if(arr[left]<=arr[mid]) {
                if(arr[left] < arr[minIdx]) minIdx = left;
                left = mid+1;
            }
            else {
                if(arr[mid]<arr[minIdx]) minIdx=mid;
                right=mid-1;
            }
        }
        return minIdx;
    }
};