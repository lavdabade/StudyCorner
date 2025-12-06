#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Code here
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        for(int i=0; i<=K; i++) {
            vector<int> temp = dis; // to avoid using updated values in same iteration
            for(auto it: flights) {
                int cs = it[0];
                int cd = it[1];
                int cc = it[2];
                if(dis[cs] != 1e9 && temp[cd] > dis[cs] + cc) {
                    temp[cd] = dis[cs] + cc;
                }
            }
            dis = temp;
        }
        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }
};