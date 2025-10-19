#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = n+1;
        for(int i=0; i<n; i++) {
            ans^=(i+1);
            ans^=arr[i];
        }
        return ans;
    }
};