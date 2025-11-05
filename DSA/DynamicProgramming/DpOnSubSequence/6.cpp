#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // code here
        int g = greed.size();
        int c = cookie.size();
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());
        int gIdx = 0;
        int cIdx = 0;
        while(cIdx < c && gIdx < g) {
            if(cookie[cIdx] >= greed[gIdx]) {
                gIdx++;
            }
            cIdx++;
        }
        return gIdx;
    }
};