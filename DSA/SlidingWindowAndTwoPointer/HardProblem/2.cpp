#include<iostream>
#include<map>

using namespace std;

class Solution {
  private:
    int lessOrEqualK(vector<int> &arr, int k) {
        map<int, int> mp;
        int front = 0;
        int rear = 0;
        int ans = 0;
        while(front < arr.size()) {
            mp[arr[front]]++;
            while(mp.size() > k) {
                mp[arr[rear]]--;
                if(mp[arr[rear]] == 0) mp.erase(arr[rear]);
                rear++;
            }
            ans += (front-rear+1);
            front++;
        }
        return ans;
    }
    
  public:
    int exactlyK(vector<int> &arr, int k) {
        // code here
        return lessOrEqualK(arr, k) - lessOrEqualK(arr, k-1);
    }
};