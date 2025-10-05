#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        bool isRotated = false;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] > nums[i]) {
                if(isRotated) 
                    return false;
                isRotated = true;
            }
        }
        if(isRotated && nums.back() > nums[0]) return false;
        return true;
    }
};