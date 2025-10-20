#include<iostream>
#include<map>

using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        map<char, int> mp;
        int front = 0;
        int rear = 0;
        int ans = -1;
        while(front < s.size()) {
            mp[s[front]]++;
            while(mp.size() > k) {
                mp[s[rear]]--;
                if(mp[s[rear]] == 0) {
                    mp.erase(s[rear]);
                }
                rear++;
            }
            if(mp.size() == k) ans = max(ans, front-rear+1);
            front++;
        }
        return ans;
    }
};