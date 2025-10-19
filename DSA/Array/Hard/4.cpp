#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(i!=0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1; j<n; j++) {
                if((j!=i+1) && arr[j]==arr[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l) {
                    int sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if(sum == target) {
                        ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                        k++;
                        while(arr[k]==arr[k-1]) k++;
                        l--;
                        while(arr[l]==arr[l+1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};