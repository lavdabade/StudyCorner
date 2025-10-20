#include<iostream>
#include<map>

using namespace std;

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        map<int, int> mp;
        int front = 0;
        int back = 0;
        int ans = 0;
        int n = arr.size();
        while(front < n) {
            mp[arr[front]]++;
            while(mp.size() > 2) {
                mp[arr[back]]--;
                if(mp[arr[back]] == 0)
                    mp.erase(arr[back]);
                back++;
            }
            ans = max(ans, front - back + 1);
            front++;
        }
        return ans;
    }
};