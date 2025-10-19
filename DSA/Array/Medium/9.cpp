#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int i=arr.size()-1;
        while(i>0 && arr[i]<=arr[i-1]) i--;
        if(i==0) {
            reverse(arr.begin(), arr.end());
            return;
        }
        i--;
        int j=arr.size()-1;
        while(arr[j]<=arr[i]) j--;
        swap(arr[j], arr[i]);
        sort(arr.begin() + i+1, arr.end());
    }
};