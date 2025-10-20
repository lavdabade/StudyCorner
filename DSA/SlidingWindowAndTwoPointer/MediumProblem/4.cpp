#include<iostream>
#include<map>

using namespace std;

class Solution {
  public:
    int characterReplacement(string& s, int k) {
        // code here
        int front = 0;
        int rear = 0;
        int ans = 0;
        map<char, int> mp;
        int highFreq = 0;
        int n = s.size();
        while(front < n) {
            mp[s[front]]++;
            highFreq = max(highFreq, mp[s[front]]);
            if((front-rear+1-k) > highFreq) {
                mp[s[rear]]--;
                if(mp[s[rear]] == 0) mp.erase(s[rear]);
                rear++;
            }
            ans = max(ans, front-rear+1);
            front++;
        }
        return ans;
    }
};