#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        vector<int> adj[26];
        vector<int> inOrder(26, 0);
        for(int i=1; i<n; i++) {
            string w1 = words[i-1];
            string w2 = words[i];
            bool noDiff = true;
            for(int j=0; j<min(w1.size(), w2.size()); j++) {
                if(w1[j]!=w2[j]) {
                    adj[w1[j]-'a'].push_back(w2[j]-'a');
                    inOrder[w2[j]-'a']++;
                    noDiff = false;
                    break;
                }
            }
            if(noDiff && w1.size()>w2.size()) return "";
        }
        int cnt=0;
        vector<int> isPresent(26, 0);
        for(auto it: words) {
            for(auto itt: it) {
                if(isPresent[itt-'a'] == 0) {
                    cnt++;
                    isPresent[itt-'a'] = 1;
                }
            }
        }
        queue<int> q;
        string ans = "";
        for(int i=0; i<26; i++) {
            if(isPresent[i]==1 && inOrder[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans+=char(node+'a');
            for(auto it: adj[node]) {
                inOrder[it]--;
                if(inOrder[it]==0) {
                    q.push(it);
                }
            }
        }
        if(ans.size() != cnt) return "";
        return ans;
    }
};