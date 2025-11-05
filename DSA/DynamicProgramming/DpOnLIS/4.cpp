#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
  private:
    static bool comp(string &a, string &b) {
        return a.size() < b.size();
    }
    
    bool isValid(string &s1, string &s2) {
        if(s1.size()+1 != s2.size()) return false;
        bool offset = false;
        int i=0;
        int j=0;
        int n = s1.size();
        while(i<n && j<n+1) {
            if(s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                if(offset) return false;
                offset = true;
                j++;
            }
        }
        return true;
    }
  
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        int maxIdx= 0;
        vector<int> lisSize(n, 1);
        for(int idx=0; idx<n; idx++) {
            for(int prevIdx=0; prevIdx<idx; prevIdx++) {
                if(isValid(words[prevIdx], words[idx]) && lisSize[prevIdx]+1 > lisSize[idx]) {
                    lisSize[idx] = 1 + lisSize[prevIdx];
                    if(lisSize[maxIdx] < lisSize[idx]) {
                        maxIdx = idx;
                    }
                }
            }
        }
        return lisSize[maxIdx];
    }
};