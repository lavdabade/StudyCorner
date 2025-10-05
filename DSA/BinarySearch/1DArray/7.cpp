#include<iostream>
#include<vector>

using namespace std;

class Solution {
    private:
        int findFirstIndex(vector<int> &nums, int target) {
            int left = 0;
            int right = nums.size()-1;
            while(left <= right) {
                int mid = left + (right-left)/2;
                if(nums[mid] >= target) right = mid-1;
                else left = mid+1;
            }
            return left;
        }

        int findLastIdx(vector<int> &nums, int target) {
            int left = 0;
            int right = nums.size()-1;
            while(left <= right) {
                int mid = left + (right-left)/2;
                if(nums[mid] <= target) left = mid+1;
                else right = mid-1;
            }
            return right;
        }
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int firstIdx = findFirstIndex(nums, target);
            if(firstIdx == nums.size() || nums[firstIdx]!=target) return {-1, -1};
            int lastIdx = findLastIdx(nums, target);
            return {firstIdx, lastIdx};
        }
};