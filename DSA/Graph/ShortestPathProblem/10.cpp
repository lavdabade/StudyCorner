#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// User function Template for C++
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        vector<int> vis(100000, 0);
        queue<int> q;
        vis[start] = 1;
        q.push(start);
        int ans = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front();
                q.pop();
                for(auto it: arr) {
                    int newNode = ((long long)it*node)%100000;
                    if(newNode == end) return ans;
                    if(vis[newNode] == 0) {
                        vis[newNode] = 1;
                        q.push(newNode);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
