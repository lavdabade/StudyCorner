#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int z = 0;
        int o = 0;
        int t = arr.size()-1;
        while(o<=t) {
            if(arr[o]==0) {
                swap(arr[z], arr[o]);
                z++;
                o++;
            }
            else if(arr[o]==1) o++;
            else {
                swap(arr[o], arr[t]);
                t--;
            }
        }
    }
};