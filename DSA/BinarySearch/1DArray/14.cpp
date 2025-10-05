#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
        int left=1;
        int right=arr.size()-2;
        if(right==-1) return 0;
        if(arr[left-1]>arr[left]) return left-1;
        if(arr[right]<arr[right+1]) return right+1;
        while(left<=right) {
            int mid=left+(right-left)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid-1]>arr[mid]) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
};