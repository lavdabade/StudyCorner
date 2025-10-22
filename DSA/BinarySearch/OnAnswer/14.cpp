#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size();
        int m = b.size();
        if(n > m) return kthElement(b, a, k);
        int left = max(0, k-m);
        int right = min(k, n);
        while(left <= right) {
            int mid1 = left + (right-left)/2;
            int mid2 = k - mid1;
            int l1 = (mid1 == 0) ? INT_MIN : a[mid1-1];
            int l2 = (mid2 == 0) ? INT_MIN : b[mid2-1];
            int r1 = (mid1 == n) ? INT_MAX : a[mid1];
            int r2 = (mid2 == m) ? INT_MAX : b[mid2];
            if((l1 <= r2) && (l2<=r1)) {
                return max(l1, l2);
            }
            else if(l1 > l2) {
                right = mid1-1;
            }
            else {
                left = mid1+1;
            }
        }
        return -1;
    }
};