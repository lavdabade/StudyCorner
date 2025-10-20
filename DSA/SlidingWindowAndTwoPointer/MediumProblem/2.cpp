#include<iostream>

using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        int front = 0;
        int rear = 0;
        int n = arr.size();
        int ans = 0;
        while(front < n) {
            sum += arr[front];
            while(sum < (front-rear+1-k)) {
                sum -= arr[rear];
                rear++;
            }
            ans = max(ans, front-rear+1);
            front++;
        }
        return ans;
    }
};