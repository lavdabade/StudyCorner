#include<iostream>
#include<vector>

using namespace std;

// User function Template for C++
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> ans(V, 1e8);
        ans[src] = 0;
        for(int i=0; i<V; i++) {
            for(auto &it: edges) {
                int s = it[0];
                int d = it[1];
                int w = it[2];
                if(ans[s]!=1e8 && ans[d] > ans[s] + w) {
                    if(i==V-1) return {-1};
                    ans[d] = ans[s] + w;
                }
            }
        }
        return ans;
    }
};