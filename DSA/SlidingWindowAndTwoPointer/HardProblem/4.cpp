#include<istream>

using namespace std;

class Solution {
  private:
    void minWindowUtil(int i, int j, int n, int m, string &s1, string &s2, string &curr, string &ans) {
        if(j == m) {
            if(ans == "" || ans.size() > curr.size()) {
                ans = curr;
            }
            return;
        }
        if(i == n) {
            return;
        }
        if(j==0) {
            if(s1[i] == s2[j]) {
                curr += s1[i];
                minWindowUtil(i+1, j+1, n, m, s1, s2, curr, ans);
                curr.pop_back();
            }
            minWindowUtil(i+1, j, n, m, s1, s2, curr, ans);
        }
        else {
            curr += s1[i];
            if(s1[i] == s2[j]) minWindowUtil(i+1, j+1, n, m, s1, s2, curr, ans);
            else minWindowUtil(i+1, j, n, m, s1, s2, curr, ans);
            curr.pop_back();
        }
    }
  
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n = s1.size();
        int m = s2.size();
        string ans = "";
        string curr = "";
        minWindowUtil(0, 0, n, m, s1, s2, curr, ans);
        return ans;
    }
};
