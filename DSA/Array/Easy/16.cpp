#include<iostream>
#include<vector>

using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    long long sum = 0;
    int front = 0;
    int back = 0;
    int n = a.size();
    int ans = 0;
    while(front<n) {
        sum+=a[front];
        while(sum > k) {
            sum -= a[back];
            back++;
        }
        if(sum==k && ans<(front-back+1)) ans = (front-back+1);
        front++;
    }
    return ans;
}