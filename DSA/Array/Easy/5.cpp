#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        vector<int> ans;
        ans.push_back(arr[0]);
        for(auto it: arr) 
            if(ans.back()!=it)
                ans.push_back(it);
        return ans;
    }
};