#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int n = grid.size();
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        while(!pq.empty()) {
            int ce = pq.top().first;
            int ci = pq.top().second.first;
            int cj = pq.top().second.second;
            pq.pop();
            ans = max(ans, ce);
            if(ci == n-1 && cj == n-1) break;
            for(int i=0; i<4; i++) {
                int ni = ci + di[i];
                int nj = cj + dj[i];
                if(ni>=0 && ni<n && nj>=0 && nj<n && vis[ni][nj]==0) {
                    vis[ni][nj] = 1;
                    pq.push({grid[ni][nj], {ni, nj}});
                }
            }
        }
        return ans;
    }
};