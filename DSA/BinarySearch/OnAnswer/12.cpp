#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        if(stations.size() <= 1) return 0.00;
        priority_queue<pair<double, pair<int, int>>> pq;
        for(int i=0; i<stations.size()-1; i++) {
            pq.push({stations[i+1] - stations[i], {stations[i+1] - stations[i], 1}});
        }
        while(K--) {
            int dis = pq.top().second.first;
            int interval = pq.top().second.second + 1;
            pq.pop();
            pq.push({(double)dis/interval, {dis, interval}});
        }
        return pq.top().first;
    }
};