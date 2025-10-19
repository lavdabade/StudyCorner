#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        for(int i=0; i<n; i++)
            reverse(mat[i].begin(), mat[i].end());
        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++)
                swap(mat[i][j], mat[j][i]);
    }
};
