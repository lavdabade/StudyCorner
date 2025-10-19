#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int e1 = INT_MIN;
        int e2 = INT_MIN;
        int c1 = 0;
        int c2 = 0;
        int n = arr.size();
        for(auto it: arr) {
            if(c1 == 0 && it != e2) {
                e1 = it;
                c1++;
            } 
            else if(c2 == 0 && it != e1) {
                e2 = it;
                c2++;
            }
            else if(it == e1)
                c1++;
            else if(it == e2)
                c2++;
            else {
                c1--;
                c2--;
            }
        }
        c1=0;
        c2=0;
        for(auto it: arr) {
            if(it == e1) c1++;
            else if(it == e2) c2++;
        }
        if(c1 > (n/3) && c2 > (n/3)) {
            if(e1 < e2) return {e1, e2};
            return {e2, e1};
        }
        else if(c1 > (n/3)) return {e1};
        else if(c2 > (n/3)) return {e2};
        return {};
    }
};