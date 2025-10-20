#include<istream>
#include<vector>

using namespace std;

class Solution {
  private:
    bool isPossible(vector<int> &freq) {
        for(auto it: freq)
            if(it < 0)
                return false;
        return true;
    }
    
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        vector<int> freq(26, 0);
        for(auto it: p) freq[it - 'a']--;
        int front = 0;
        int rear = 0;
        string ans = "";
        while(front < s.size()) {
            freq[s[front] - 'a']++;
            while(isPossible(freq)) {
                if(ans=="" || ans.size() > (front-rear+1)) 
                    ans = s.substr(rear, front-rear+1);
                freq[s[rear] - 'a']--;
                rear++;
            }
            front++;
        }
        return ans;
    }
};