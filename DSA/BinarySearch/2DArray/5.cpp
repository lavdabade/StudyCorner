#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    int getUpperBound(vector<int> &arr, int x) {
        int left = 0;
        int right = arr.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(arr[mid] <= x) left=mid+1;
            else right = mid-1;
        }
        return left;
    }
    
    int getNoOfLessOrEqual(vector<vector<int>> &mat, int x) {
        int noOfLessOrEqual = 0;
        for(auto it: mat) 
            noOfLessOrEqual += getUpperBound(it, x);
        return noOfLessOrEqual;
    }
    
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int left = INT_MAX;
        int right = INT_MIN;
        for(auto it: mat) {
            left = min(left, it[0]);
            right = max(right, it[m-1]);
        }
        while(left <= right) {
            int mid = left + (right-left)/2;
            int noOfLessOrEqual = getNoOfLessOrEqual(mat, mid);
            if(noOfLessOrEqual < (n*m/2) + 1) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};
