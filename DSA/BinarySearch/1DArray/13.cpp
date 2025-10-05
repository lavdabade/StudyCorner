#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int single(vector<int>& arr) {
        // code here
        int left=1;
        int right=arr.size()-2;
        if(right == -1) return arr[0];
        if(arr[left-1]!=arr[left]) return arr[0];
        if(arr[right]!=arr[right+1]) return arr[right+1];
        while(left<=right) {
            int mid=left+(right-left)/2;
            if(arr[mid-1]!=arr[mid] && arr[mid]!=arr[mid+1]) return arr[mid];
            else if(mid%2 == 0) {
                if(arr[mid]==arr[mid+1]) left=mid+1;
                else right=mid-1;
            }
            else {
                if(arr[mid-1]==arr[mid]) left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};