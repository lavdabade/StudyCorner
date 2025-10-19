#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        int gap = (n+m)/2 + (n+m)%2;
        while(true) {
            for(int i=0; i<(n+m-gap); i++) {
                int i1 = i;
                int i2 = i+gap;
                if(i2 < n) {
                    if(a[i2] < a[i1]) 
                        swap(a[i1], a[i2]);
                }
                else if(i1 >= n) {
                    if(b[i2-n] < b[i1-n]) 
                        swap(b[i1-n], b[i2-n]);
                }
                else {
                    if(a[i1] > b[i2-n]) 
                        swap(a[i1], b[i2-n]);
                }
            }
            if(gap == 1) break;
            gap = (gap/2) + (gap%2);
        }
    }
};