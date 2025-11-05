#include<iostream>
#include<vector>
#include<string>

using namespace std;


// User function Template for C++

class Solution {
  private:
    bool isPalin(int start, int end, string &s) {
        while(start < end) {
            if(s[start]!=s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
  public:
    int palPartition(string &s) {
        // code here
        int n = s.size();
        if(isPalin(0, n-1, s)) return 0;
        vector<int> dp(n+1, 0);
        for(int start=n-1; start>=0; start--) {
            int ans = INT_MAX;
            for(int k=start; k<n; k++) {
                if(isPalin(start, k, s)) {
                    ans = min(ans, 1 + dp[k+1]);
                }
            }
            dp[start] = ans;
        }
        return dp[0]-1;
    }
};



// User function Template for C++
class Solution_Memoization_1D {
  private:
    bool isPalin(int start, int end, string &s) {
        while(start < end) {
            if(s[start]!=s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    int palPartitionUtil(int start, int n, string &s, vector<int> &dp) {
        if(start == n) return 0;
        if(dp[start] != -1) return dp[start];
        int ans = INT_MAX;
        for(int k=start; k<n; k++) {
            if(isPalin(start, k, s)) {
                ans = min(ans, 1 + palPartitionUtil(k+1, n, s, dp));
            }
        }
        return dp[start] = ans;
    }
    
  public:
    int palPartition(string &s) {
        // code here
        int n = s.size();
        if(isPalin(0, n-1, s)) return 0;
        vector<int> dp(n, -1);
        return palPartitionUtil(0, n, s, dp)-1;
    }
};



// User function Template for C++
class Solution_Recursion_1D {
  private:
    bool isPalin(int start, int end, string &s) {
        while(start < end) {
            if(s[start]!=s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    int palPartitionUtil(int start, int n, string &s) {
        if(start == n) return 0;
        int ans = INT_MAX;
        for(int k=start; k<n; k++) {
            if(isPalin(start, k, s)) {
                ans = min(ans, 1 + palPartitionUtil(k+1, n, s));
            }
        }
        return ans;
    }
    
  public:
    int palPartition(string &s) {
        // code here
        int n = s.size();
        if(isPalin(0, n-1, s)) return 0;
        return palPartitionUtil(0, n, s)-1;
    }
};


// User function Template for C++
class Solution_Memoization_2D {
  private:
    bool isPalin(int start, int end, string &s) {
        while(start < end) {
            if(s[start]!=s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    int palPartitionUtil(int start, int end, string &s, vector<vector<int>> &dp) {
        if(start == end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        if(isPalin(start, end, s)) return dp[start][end] = 0;
        int ans = INT_MAX;
        for(int k=start; k<end; k++) {
            int curr = 1 + palPartitionUtil(start, k, s, dp) + palPartitionUtil(k+1, end, s, dp);
            ans = min(ans, curr);
        }
        return dp[start][end] = ans;
    }
    
  public:
    int palPartition(string &s) {
        // code here
        int n = s.size();
        if(isPalin(0, n-1, s)) return 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return palPartitionUtil(0, n-1, s, dp);
    }
};



// User function Template for C++
class Solution_Recursion_2D {
  private:
    bool isPalin(int start, int end, string &s) {
        while(start < end) {
            if(s[start]!=s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    int palPartitionUtil(int start, int end, string &s) {
        if(start == end) return 0;
        if(isPalin(start, end, s)) return 0;
        int ans = INT_MAX;
        for(int k=start; k<end; k++) {
            int curr = 1 + palPartitionUtil(start, k, s) + palPartitionUtil(k+1, end, s);
            ans = min(ans, curr);
        }
        return ans;
    }
    
  public:
    int palPartition(string &s) {
        // code here
        int n = s.size();
        if(isPalin(0, n-1, s)) return 0;
        return palPartitionUtil(0, n-1, s);
    }
};