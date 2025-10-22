#include<iostream>

using namespace std;

class Solution {
  private:
    long long int getNthNum(int mid, int n, int m) {
        long long int ans = 1;
        for(int i=0; i<n; i++) {
            ans *= mid;
            if(ans > m) return ans;
        }
        return ans;
    }
    
  public:
    int nthRoot(int n, int m) {
        // Code here
        int left = 1;
        int right = m;
        while(left <= right) {
            int mid = left + (right-left)/2;
            long long int nthNum = getNthNum(mid, n, m);
            if(nthNum == m) return mid;
            else if(nthNum > m) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};