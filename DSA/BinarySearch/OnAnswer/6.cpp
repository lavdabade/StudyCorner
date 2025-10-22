#include<iostream>

using namespace std;

// User function Template for C++
class Solution {
  private:
    int getNoOfDays(int arr[], int n, int weightLimit) {
        int days = 0;
        int currWeight = 0;
        for(int i=0; i<n; i++) {
            if(currWeight + arr[i] <= weightLimit) {
                currWeight += arr[i];
            }
            else {
                days++;
                currWeight = arr[i];
            }
        }
        return days+1;
    }
  
  public:
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int left = INT_MIN;
        int right = 0;
        for(int i=0; i<n; i++) {
            left = max(left, arr[i]);
            right += arr[i];
        }
        int ans = -1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int noOfDays = getNoOfDays(arr, n, mid);
            if(noOfDays <= d) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};