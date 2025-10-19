#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> triplets(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(i!=0 && arr[i]==arr[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k) {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum == 0) {
                    ans.push_back({arr[i], arr[j], arr[k]});
                    j++;
                    while(arr[j]==arr[j-1]) j++;
                    k--;
                    while(arr[k]==arr[k+1]) k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }
        return ans;
    }
};
