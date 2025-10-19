#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        set<int> st;
        int ans = 0;
        for(auto it: arr) st.insert(it);
        for(auto it: arr)
            if(st.find(it-1) == st.end()) {
                int currLen=1;
                int offSet=1;
                while(st.find(it+offSet)!=st.end()) {
                    currLen++;
                    offSet++;
                }
                ans = max(currLen, ans);
            }
        return ans;
    }
};