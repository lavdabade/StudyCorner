#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low >= high) return;
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int idx = low;
        for(int i=low; i<high; i++) {
            if(arr[i] < arr[high]) {
                swap(arr[i], arr[idx]);
                idx++;
            }
        }
        swap(arr[idx], arr[high]);
        return idx;
    }
};