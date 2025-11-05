#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    int robUtil(vector<int> &house, int n) {
        int prev2 = house[0];
        int prev1 = max(house[0], house[1]);
        for(int idx=2; idx<n-1; idx++) {
            int curr = max(house[idx] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> first;
        vector<int> last;
        for(int i=0; i<n; i++) {
            if(i!=n-1) first.push_back(nums[i]);
            if(i!=0) last.push_back(nums[i]);
        }
        return max(robUtil(first, n), robUtil(last, n));
    }
};


class Solution_Tabulation {
private:
    int robUtil(vector<int> &house, int n) {
        vector<int> dp(n-1);
        dp[0] = house[0];
        dp[1] = max(house[0], house[1]);
        for(int idx=2; idx<n-1; idx++) {
            dp[idx] = max(house[idx] + dp[idx-2], dp[idx-1]);
        }
        return dp[n-2];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> first;
        vector<int> last;
        for(int i=0; i<n; i++) {
            if(i!=n-1) first.push_back(nums[i]);
            if(i!=0) last.push_back(nums[i]);
        }
        return max(robUtil(first, n), robUtil(last, n));
    }
};


class Solution_Memoization {
private:
    int robUtil(int idx, vector<int> &house, vector<int> &dp) {
        if(idx == 0) return house[0];
        if(idx == 1) return max(house[0], house[1]);
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max(house[idx] + robUtil(idx-2, house, dp), robUtil(idx-1, house, dp));
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> first;
        vector<int> last;
        for(int i=0; i<n; i++) {
            if(i!=n-1) first.push_back(nums[i]);
            if(i!=0) last.push_back(nums[i]);
        }
        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);
        return max(robUtil(n-2, first, dp1), robUtil(n-2, last, dp2));
    }
};


class Solution_Recursion {
private:
    int robUtil(int idx, vector<int> &house) {
        if(idx == 0) return house[0];
        if(idx == 1) return max(house[0], house[1]);
        return max(house[idx] + robUtil(idx-2, house), robUtil(idx-1, house));
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> first;
        vector<int> last;
        for(int i=0; i<n; i++) {
            if(i!=n-1) first.push_back(nums[i]);
            if(i!=0) last.push_back(nums[i]);
        }
        return max(robUtil(n-2, first), robUtil(n-2, last));
    }
};