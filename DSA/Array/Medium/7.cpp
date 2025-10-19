#include<iostream>
#include<vector>

using namespace std;


int maximumProfit(vector<int> &prices){
    // Write your code here.
    int minTillNow = prices[0];
    int maxProfit = 0;
    for(auto it: prices) {
        maxProfit = max(maxProfit, it - minTillNow);
        minTillNow = min(minTillNow, it);
    }
    return maxProfit;
}