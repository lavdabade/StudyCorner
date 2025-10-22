#include<iostream>
#include<vector>

using namespace std;

// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int i = 0;
        int j = mat[0].size()-1;
        int n = mat.size();
        int m = mat[0].size();
        while(i<n && j>=0) {
            if(mat[i][j] == x) return true;
            while(j>=0 && mat[i][j]>x) j--;
            while(i<n && mat[i][j]<x) i++;
        }
        return false;
    }
};