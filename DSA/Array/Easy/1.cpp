#include<iostream>
#include<vector>

using namespace std;

class Solution1 {
  public:
    int largest(vector<int> &arr) {
        // code here
        return *max_element(arr.begin(), arr.end());
    }
};

class Solution2 {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxi = INT_MIN;
        for(auto it: arr) {
            maxi = max(maxi, it);
        }
        return maxi;
    }
};