#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    int getSumOfCeil(vector<int> &arr, int divisor) {
        int sum = 0;
        for(auto it: arr) {
            sum += ((it/divisor) + ((it%divisor) == 0 ? 0 : 1));
        }
        return sum;
    }
    
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int sumOfCeil = getSumOfCeil(arr, mid);
            if(sumOfCeil <= k) {
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        return ans;
    }
};
