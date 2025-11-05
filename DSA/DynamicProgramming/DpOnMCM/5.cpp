#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
private:
    bool isPalin(int start, int end, string &s) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void partitionUtil(int idx, int n, string &s, vector<string> &curr, vector<vector<string>> &ans) {
        if(idx == n) {
            ans.push_back(curr);
            return;
        }
        for(int k=idx; k<n; k++) {
            if(isPalin(idx, k, s)) {
                curr.push_back(s.substr(idx, k-idx+1));
                partitionUtil(k+1, n, s, curr, ans);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        int n = s.size();
        partitionUtil(0, n, s, curr, ans);
        return ans;
    }
};