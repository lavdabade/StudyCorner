#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int firstLargest = arr[0];
        int secondLargest = -1;
        for(int i=1; i<arr.size(); i++) {
            if(arr[i] == firstLargest) continue;
            if(arr[i] > firstLargest) {
                secondLargest = firstLargest;
                firstLargest = arr[i];
            }
            else if(arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }
        return secondLargest;
    }
};