#include<iostream>
#include<vector>

using namespace std;

// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        for(auto it: edges) {
            dis[it[0]][it[1]] = it[2];
            dis[it[1]][it[0]] = it[2];
        }
        for(int i=0; i<n; i++) dis[i][i] = 0;
        for(int via=0; via<n; via++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dis[i][via]==1e9 || dis[via][j]==1e9) continue;
                    dis[i][j] = min(dis[i][j], dis[i][via]+dis[via][j]);
                }
            }
        }
        int ans = 0;
        int cityCount = n;
        for(int i=0; i<n; i++) {
            int currCityCount = 0;
            for(int j=0; j<n; j++) {
                if(dis[i][j]<=distanceThreshold) {
                    currCityCount++;
                }
            }
            if(currCityCount <= cityCount) {
                cityCount = currCityCount;
                ans = i;
            }
        }
        return ans;
    }
};
