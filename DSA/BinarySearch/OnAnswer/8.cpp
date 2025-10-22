#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    int getNoOfCows(vector<int> &stalls, int dis) {
        int noOfCows = 1;
        int prevStall = stalls[0];
        for(int i=1; i<stalls.size(); i++) {
            if(stalls[i]-prevStall >= dis) {
                noOfCows++;
                prevStall = stalls[i];
            }
        }
        return noOfCows;
    }
    
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int left = 1;
        int right = stalls.back()-stalls[0];
        while(left <= right) {
            int mid = left + (right-left)/2;
            int noOfCows = getNoOfCows(stalls, mid);
            if(noOfCows >= k) left = mid+1;
            else right = mid-1;
        }
        return right;
    }
};