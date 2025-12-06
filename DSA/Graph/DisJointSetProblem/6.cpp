#include<iostream>
#include<vector>
#include<map>

using namespace std;

class DisJoint {
  private:
    vector<int> parent;
    vector<int> size;
  
  public:
    DisJoint(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }
  
    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    
    void unionBySize(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if(up == vp) return;
        if(size[up] < size[vp]) {
            size[vp] += size[up];
            parent[up] = vp;
        }
        else {
            size[up] += size[vp];
            parent[vp] = up;
        }
    }
};

class Solution {
  public:
    vector<vector<string>> accMerge(vector<vector<string>>& arr) {
        // code here
        map<string, int> mp;
        int n = arr.size();
        DisJoint ds(n);
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++) {
            for(int j=1; j<arr[i].size(); j++) {
                if(mp.find(arr[i][j]) == mp.end()) {
                    mp[arr[i][j]] = i;
                }
                else {
                    ds.unionBySize(i, mp[arr[i][j]]);
                }
            }
        }
        vector<vector<string>> temp(n);
        for(auto it: mp) {
            int p = ds.findParent(it.second);
            temp[p].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++) {
            if(temp[i].size() == 0) continue;
            vector<string> t;
            sort(temp[i].begin(), temp[i].end());
            t.push_back(arr[i][0]);
            t.insert(t.end(), temp[i].begin(), temp[i].end());
            ans.push_back(t);
        }
        return ans;
    }
};
