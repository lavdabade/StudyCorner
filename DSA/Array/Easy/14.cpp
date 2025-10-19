#include<iostream>
#include<vector>

using namespace std;

// User function template for C++
class Solution {
  public:
    int search(int n, int arr[]) {
        // code
        int ans = 0;
        for(int i=0; i<n; i++)
            ans^=arr[i];
        return ans;
    }
};