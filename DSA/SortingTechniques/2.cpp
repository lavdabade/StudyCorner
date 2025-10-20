#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i=1; i<n; i++) {
            int curr = arr[i];
            int j = i;
            while(j>0 && arr[j-1]>curr) {
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = curr;
        }
    }
};