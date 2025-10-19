#include<iostream>
#include<vector>

using namespace std;

// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> positive;
        vector<int> negative;
        for(auto it: arr) {
            if(it >= 0) positive.push_back(it);
            else negative.push_back(it);
        }
        int i=0;
        int j=0;
        int k=0;
        while(i<positive.size() && i<negative.size()) {
            arr[k++]=positive[i++];
            arr[k++]=negative[j++];
        }
        while(i<positive.size()) 
            arr[k++]=positive[i++];
        while(j<negative.size())
            arr[k++]=negative[j++];
    }
};