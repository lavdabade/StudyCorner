#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

class Solution {
  private:
    int getNoOfStudents(vector<int> &arr, int pages) {
        int noOfStudents = 0;
        int currPages = 0;
        for(int i=0; i<arr.size(); i++) {
            if(currPages + arr[i] <= pages) {
                currPages += arr[i];
            }
            else {
                noOfStudents++;
                currPages = arr[i];
            }
        }
        return noOfStudents+1;
    }
    
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);
        while(left <= right) {
            int mid = left + (right-left)/2;
            int noOfStudent = getNoOfStudents(arr, mid);
            if(noOfStudent > k) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};