#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> ans;
        int i=0;
        int j=0;
        int n=a.size();
        int m=b.size();
        while(i<n && j<m) {
            if(!ans.empty() && ans.back()==a[i]) i++;
            else if(!ans.empty() && ans.back()==b[j]) j++;
            else if(a[i]<b[j]) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }
        while(i<n) 
            if(!ans.empty() && ans.back()==a[i]) i++;
            else ans.push_back(a[i++]);
        while(j<m) 
            if(!ans.empty() && ans.back()==b[j]) j++;
            else ans.push_back(b[j++]);
        return ans;
    }
};