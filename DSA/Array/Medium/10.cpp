#include<iostream>
#include<vector>

using namespace std;

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int leader = arr.back();
        vector<int> ans;
        for(int i=arr.size()-1; i>=0; i--) {
            if(arr[i]>=leader) {
                ans.push_back(arr[i]);
                leader=arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};