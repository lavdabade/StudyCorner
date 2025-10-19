#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    int merge(int i, int j, int k, vector<int> &arr) {
        vector<int> temp;
        int i1 = i;
        int i2 = j+1;
        int ans = 0;
        while(i1<=j && i2<=k) {
            if(arr[i1] > 2*arr[i2]) {
                ans += (j-i1+1);
                i2++;
            }
            else i1++;
        }
        i1 = i;
        i2 = j+1;
        while(i1<=j && i2<=k) {
            if(arr[i1] <= arr[i2]) {
                temp.push_back(arr[i1]);
                i1++;
            }
            else {
                temp.push_back(arr[i2]);
                i2++;
            }
        }
        while(i1<=j) {
            temp.push_back(arr[i1]);
            i1++;
        }
        while(i2<=k) {
            temp.push_back(arr[i2]);
            i2++;
        }
        for(int x = 0; x < temp.size(); x++) 
            arr[i+x] = temp[x];
        return ans;
    }
  
    int mergeSort(int i, int j, vector<int> &arr) {
        if(i>=j) return 0;
        int ans = 0;
        int mid = (i+j)/2;
        ans += mergeSort(i, mid, arr);
        ans += mergeSort(mid+1, j, arr);
        ans += merge(i, mid, j, arr);
        return ans;
    }
    
  public:
    int countRevPairs(vector<int> &arr) {
        // Code here
        int n = arr.size();
        return mergeSort(0, n-1, arr);
    }
};