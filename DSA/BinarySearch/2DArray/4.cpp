#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int left = 0;
        int right = n-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int maxIdx = 0;
            for(int i=1; i<n; i++) {
                if(mat[maxIdx][mid] < mat[i][mid]) {
                    maxIdx = i;
                }
            }
            int leftElement = (mid == 0) ? INT_MIN : mat[maxIdx][mid-1];
            int rightElement = (mid == m-1) ? INT_MIN : mat[maxIdx][mid+1];
            if(mat[maxIdx][mid] >= leftElement && mat[maxIdx][mid] >= rightElement) return {maxIdx, mid};
            else if(mat[maxIdx][mid] < leftElement) right = mid-1;
            else left = mid+1;
        }
        return {-1, -1};
    }
};