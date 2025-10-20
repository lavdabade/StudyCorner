#include<iostream>
#include<map>

using namespace std;

class Solution {
  private:
    int countSubstringLessOrEqual(string s, int k) {
        map<char, int> mp;
        int front = 0;
        int rear = 0;
        int ans = 0;
        int n = s.size();
        while(front < n) {
            mp[s[front]]++;
            while(mp.size() > k) {
                mp[s[rear]]--;
                if(mp[s[rear]]==0) mp.erase(s[rear]);
                rear++;
            }
            ans += (front-rear+1);
            front++;
        }
        return ans;
    }
  
  public:
    int countSubstring(string s) {
        // Code here
        return countSubstringLessOrEqual(s, 3) - countSubstringLessOrEqual(s, 2);
    }
};