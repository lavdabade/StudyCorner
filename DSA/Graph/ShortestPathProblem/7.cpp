#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
  public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int> delay(V, 1e9);
        delay[src] = 0;
        for(int i=0; i<V-1; i++) {
            for(auto it: edges) {
                int cs = it[0];
                int cd = it[1];
                int dly = it[2];
                if(delay[cs] != 1e9 && delay[cd] > delay[cs] + dly) {
                    delay[cd] = delay[cs] + dly;
                }
            }
        }
        int maxDelay = *max_element(delay.begin(), delay.end());
        if(maxDelay == 1e9) return -1;
        return maxDelay;
    }
};