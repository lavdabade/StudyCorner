#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    void merge(vector<int> &arr, int l, int m, int r) {
        int i1 = l;
        int i2 = m+1;
        vector<int> temp;
        while(i1<=m && i2<=r)
            if(arr[i1] < arr[i2]) 
                temp.push_back(arr[i1++]);
            else 
                temp.push_back(arr[i2++]);
        while(i1<=m)
            temp.push_back(arr[i1++]);
        while(i2<=r)
            temp.push_back(arr[i2++]);
        for(int i=0; i<temp.size(); i++)
            arr[l+i] = temp[i];
    }
    
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};