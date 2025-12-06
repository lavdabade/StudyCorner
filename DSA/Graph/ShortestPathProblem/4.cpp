#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// User function Template for C++
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source.first == destination.first && source.second == destination.second) return 0;
        if(grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0) return -1;
        int n = grid.size();
        int m = grid[0].size();
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int curr = 1;
        queue<pair<int, int>> q;
        q.push({source.first, source.second});
        vis[source.first][source.second] = 1;
        while(!q.empty()) {
            int t=q.size();
            while(t--) {
                int ci = q.front().first;
                int cj = q.front().second;
                q.pop();
                for(int i=0; i<4; i++) {
                    int ni = ci + di[i];
                    int nj = cj + dj[i];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1 && vis[ni][nj]==0) {
                        if(destination.first == ni && destination.second == nj) return curr;
                        vis[ni][nj]=1;
                        q.push({ni, nj});
                    }
                }
            }
            curr++;
        }
        return -1;
    }
};
