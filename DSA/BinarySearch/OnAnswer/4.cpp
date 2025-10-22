#include<iostream>
#include<vector>

using namespace std;

class Solution {
  private:
    int getNoOfBouquets(vector<int> &arr, int days, int k) {
        int noOfBouquets = 0;
        int cnt = 0;
        for(auto it: arr) {
            if(it <= days) {
                cnt++;
                if(cnt == k) {
                    noOfBouquets++;
                    cnt = 0;
                }
            }
            else {
                cnt = 0;
            }
        }
        return noOfBouquets;
    }
    
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int left = *min_element(arr.begin(), arr.end());
        int right = *max_element(arr.begin(), arr.end());
        bool ansExists = false;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int noOfBouquets = getNoOfBouquets(arr, mid, k);
            if(noOfBouquets >= m) {
                right = mid-1;
                ansExists = true;
            }
            else left = mid+1;
        }
        if(!ansExists) return -1;
        return left;
    }
};