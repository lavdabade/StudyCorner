#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        bool isRow = false;
        bool isCol = false;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++)
            if(mat[i][0] == 0) {
                isCol = true;
                break;
            }
        for(int j=0; j<m; j++) 
            if(mat[0][j] == 0) {
                isRow = true;
                break;
            }
        
        for(int i=1; i<n; i++)
            for(int j=1; j<m; j++)
                if(mat[i][j]==0) {
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
                
        for(int i=1; i<n; i++)
            if(mat[i][0] == 0)
                for(int j=1; j<m; j++) mat[i][j]=0;
                
        for(int j=1; j<m; j++) 
            if(mat[0][j] == 0) 
                for(int i=1; i<n; i++) mat[i][j] = 0;
                
        if(isCol) 
            for(int i=0; i<n; i++) mat[i][0] = 0;
            
        if(isRow)
            for(int j=0; j<m; j++) mat[0][j] = 0;
    }
};