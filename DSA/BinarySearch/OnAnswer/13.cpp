#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        if(n > m) return medianOf2(b, a);
        int left = 0;
        int right = n;
        int leftCount = (n+m+1)/2;
        while(left <= right) {
            int mid1 = left + (right-left)/2;
            int mid2 = leftCount - mid1;
            int l1 = (mid1 == 0) ? INT_MIN : a[mid1-1];
            int l2 = (mid2 == 0) ? INT_MIN : b[mid2-1];
            int r1 = (mid1 == n) ? INT_MAX : a[mid1];
            int r2 = (mid2 == m) ? INT_MAX : b[mid2];
            if((l1 <= r2) && (l2 <= r1)) {
                if((n+m)%2 == 1) return max(l1, l2);
                else return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if(l1 > r2) {
                right = mid1-1;
            }
            else {
                left = mid1+1;
            }
        }
        return -1;
    }
};