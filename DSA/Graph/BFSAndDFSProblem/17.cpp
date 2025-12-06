#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

// User function Template for C++
class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        int level = 0;
        usedOnLevel.push_back(beginWord);
        while(!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            if(vec.size() > level) {
                level++;
                for(auto it: usedOnLevel) {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            string currWord = vec.back();
            if(currWord == endWord) {
                if(ans.size()==0 || ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }
            for(int i=0; i<currWord.size(); i++) {
                char orig = currWord[i];
                for(int j=0; j<26; j++) {
                    currWord[i] = char(j+'a');
                    if(st.find(currWord) != st.end()) {
                        vec.push_back(currWord);
                        q.push(vec);
                        usedOnLevel.push_back(currWord);
                        vec.pop_back();
                    }
                }
                currWord[i] = orig;
            }
        }
        return ans;
    }
};