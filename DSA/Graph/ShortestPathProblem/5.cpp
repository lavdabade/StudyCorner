#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        while(!pq.empty()) {
            int ce = pq.top()[0];
            int ci = pq.top()[1];
            int cj = pq.top()[2];
            pq.pop();
            if(ci==n-1 && cj==m-1) return ce;
            if(ce > dis[ci][cj]) continue;
            for(int i=0; i<4; i++) {
                int ni = ci + di[i];
                int nj = cj + dj[i];
                if(ni>=0 && ni<n && nj>=0 && nj<m) {
                    int ne = max(ce, abs(mat[ci][cj] - mat[ni][nj]));
                    if(ne < dis[ni][nj]) {
                        dis[ni][nj] = ne;
                        pq.push({ne, ni, nj});
                    }
                }
            }
        }
        return -1;
    }
};
