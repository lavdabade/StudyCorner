#include<iostream>

using namespace std;

class Solution {
  private:
    int countSubarraysLessOrEqual(vector<int> &arr, int k) {
        int n = arr.size();
        int oddCount = 0;
        int front = 0;
        int back = 0;
        int ans = 0;
        while(front < n) {
            if(arr[front]%2 == 1) oddCount++;
            while(oddCount > k) {
                if(arr[back]%2 == 1) oddCount--;
                back++;
            }
            ans += (front-back+1);
            front++;
        }
        return ans;
    }
    
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        return countSubarraysLessOrEqual(arr, k) - countSubarraysLessOrEqual(arr, k-1);
    }
};