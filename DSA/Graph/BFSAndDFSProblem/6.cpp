#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        if(image[sr][sc] == newColor) return image;
        int oldColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        q.push({sr, sc});
        image[sr][sc]=newColor;
        while(!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==oldColor) {
                    image[nr][nc] = newColor;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};