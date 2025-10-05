#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        if(startWord == targetWord) return 0;
        if(find(wordList.begin(), wordList.end(), targetWord) == wordList.end()) return 0;
        set<string> st;
        queue<string> q;
        int ans=1;
        for(auto it: wordList) st.insert(it);
        st.erase(startWord);
        q.push(startWord);
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            while(sz--) {
                string node = q.front();
                q.pop();
                for(int idx=0; idx<node.size(); idx++) {
                    char orig = node[idx];
                    for(char ch = 'a'; ch<='z'; ch++) {
                        if(ch!=orig) {
                            node[idx]=ch;
                            if(st.find(node)!=st.end()) {
                                if(node == targetWord) return ans;
                                q.push(node);
                                st.erase(node);
                            }
                        }
                    }
                    node[idx]=orig;
                }
            }
        }
        return 0;
    }
};