#include<iostream>
#include<vector>

using namespace std;

// User function template for C++
class Solution {
  private:
    int getLowerBound(vector<int> &arr, int n) {
        int left = 0;
        int right = n-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(arr[mid]==1) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
  
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ansIdx = -1;
        int n = arr[0].size();
        int ans = n;
        for(int i = 0; i<arr.size(); i++) {
            int temp = getLowerBound(arr[i], n);
            if(temp >= 0 && temp < ans) {
                ans = temp;
                ansIdx = i;
            }
        }
        return ansIdx;
    }
};