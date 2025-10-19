#include<iostream>
#include<vector>

using namespace std;

vector<int> maximumsumSubarray(vector<int> &arr , int n)
{
    //Write your code here
    int ansStart = -1;
    int ansEnd = -1;
    int currStart = 0;
    int sumTillNow = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<arr.size(); i++) {
        sumTillNow += arr[i];
        if(maxSum < sumTillNow) {
            ansStart = currStart;
            ansEnd = i;
            maxSum = sumTillNow;
        }
        if(sumTillNow < 0) {
            currStart = i+1;
            sumTillNow = 0;
        }
    }
    vector<int> ans;
    for(int i=ansStart; i<=ansEnd; i++) 
        ans.push_back(arr[i]);
    return ans;
}
