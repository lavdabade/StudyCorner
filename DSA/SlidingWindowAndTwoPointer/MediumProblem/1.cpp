#include<iostream>
#include<map>

using namespace std;

class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        map<char, int> mp;
        int front = 0;
        int back = 0;
        int n = s.size();
        int ans = 0;
        while(front < n) {
            mp[s[front]]++;
            while(mp.size() < (front-back+1)) {
                mp[s[back]]--;
                if(mp[s[back]] == 0) mp.erase(s[back]);
                back++;
            }
            ans = max(ans, front-back+1);
            front++;
        }
        return ans;
    }
};