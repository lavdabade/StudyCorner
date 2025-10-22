#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int left = 0;
        int right = n*m-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int i = mid/m;
            int j = mid%m;
            if(mat[i][j] == x) return true;
            else if(mat[i][j] < x) left = mid+1;
            else right = mid-1;
        }
        return false;
    }
};