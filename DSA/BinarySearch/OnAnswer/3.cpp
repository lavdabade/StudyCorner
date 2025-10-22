#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    int getRequiredHours(vector<int> &arr, int speed) {
        int hrs = 0;
        for(auto it: arr) {
            hrs += ((it/speed) + ((it%speed) == 0 ? 0 : 1));
        }
        return hrs;
    }
    
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());
        if(arr.size() == k) return right;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int reqHrs = getRequiredHours(arr, mid);
            if(reqHrs <= k) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};