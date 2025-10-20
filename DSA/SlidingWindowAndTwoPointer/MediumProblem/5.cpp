#include<iostream>

using namespace std;

class Solution {
  private:
    int numberOfSubarraysLessOrEqual(vector<int>& arr, int target) {
        // Your code goes here.
        int n = arr.size();
        int front = 0;
        int back = 0;
        int sum = 0;
        int ans = 0;
        while(front < n) {
            sum += arr[front];
            while(sum > target) {
                sum -= arr[back];
                back++;
            }
            ans += (front-back+1);
            front++;
        }
        return ans;
    }
    
  public:
    int numberOfSubarrays(vector<int>& arr, int target) {
        return numberOfSubarraysLessOrEqual(arr, target) - numberOfSubarraysLessOrEqual(arr, target-1);
    }
};