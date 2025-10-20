#include<iostream>

using namespace std;

class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        // code here.
        int sum = 0;
        int n = cardPoints.size();
        for(int i=0; i<k; i++) sum += cardPoints[i];
        if(k==n) return sum;
        int ans = sum;
        for(int i=k-1, j=n-1; i>=0; i--, j--) {
            sum -= cardPoints[i];
            sum += cardPoints[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};