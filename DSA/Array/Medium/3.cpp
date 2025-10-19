#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int ele = 0;
        int cnt = 0;
        for(auto it: arr) {
            if(cnt == 0) {
                ele = it;
                cnt++;
            }
            else if(it == ele)
                cnt++;
            else
                cnt--;
        }
        cnt=0;
        for(auto it: arr) 
            if(it == ele)
                cnt++;
        if(cnt <= arr.size()/2) return -1;
        return ele;
    }
};