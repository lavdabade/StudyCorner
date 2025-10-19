#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int xr = 0;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            xr ^= arr[i];
            xr ^= (i+1);
        }
        int num = (xr & (~(xr-1)));
        int z = 0;
        int o = 0;
        for(int i=0; i<n; i++) {
            if((arr[i] & num)==0) z ^= arr[i];
            else o ^= arr[i];
            if(((i+1) & num)==0) z ^= (i+1);
            else o ^= (i+1);
        }
        for(auto it: arr)
            if(it == o) 
                return {o, z};
        return {z, o};
    }
};