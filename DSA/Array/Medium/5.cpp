#include<iostream>
#include<vector>

using namespace std;

long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long ans = 0;
    long long sumTillNow = 0;
    for(auto it: arr) {
        sumTillNow+=it;
        ans=max(ans, sumTillNow);
        if(sumTillNow < 0) 
            sumTillNow = 0;
    }
    return ans;
}