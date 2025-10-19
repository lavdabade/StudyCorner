#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        int element = n*m;
        
        int rs = 0;
        int re = n-1;
        int cs = 0;
        int ce = m-1;
        
        vector<int> ans;
        
        while(cnt < element) {
            for(int j=cs; j<=ce && cnt < element; j++) {
                ans.push_back(mat[rs][j]);
                cnt++;
            }
            rs++;
            for(int i=rs; i<=re && cnt < element; i++) {
                ans.push_back(mat[i][ce]);
                cnt++;
            }
            ce--;
            for(int j=ce; j>=cs && cnt < element; j--) {
                ans.push_back(mat[re][j]);
                cnt++;
            }
            re--;
            for(int i=re; i>=rs && cnt < element; i--) {
                ans.push_back(mat[i][cs]);
                cnt++;
            }
            cs++;
        }
        return ans;
    }
};