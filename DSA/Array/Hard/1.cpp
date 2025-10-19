#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int> ans(1, 1);
        int val = 1;
        for(int i=1; i<n; i++) {
            val *= (n-i);
            val /= (i);
            ans.push_back(val);
        }
        return ans;
    }
};