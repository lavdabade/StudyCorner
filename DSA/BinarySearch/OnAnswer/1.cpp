#include<iostream>

using namespace std;

class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int left = 1;
        int right = n;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int squareOfMid = mid*mid;
            if(squareOfMid <= n) left = mid+1;
            else right = mid-1;
        }
        return right;
    }
};