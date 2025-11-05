#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
    int maximalRectangleUtil(vector<int> histogram) {
        stack<int> st;
        histogram.push_back(0);
        int n = histogram.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            while(!st.empty() && histogram[st.top()] > histogram[i]) {
                int height = histogram[st.top()];
                st.pop();
                int width = (st.empty() ? i : i - st.top() - 1);
                ans = max(ans, height*width);
            }
            st.push(i);
        }
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> histogram(n, 0);
        int ans = 0;
        for(auto it: matrix) {
            for(int i=0; i<n; i++) {
                if(it[i] == '0') {
                    histogram[i] = 0;
                }
                else {
                    histogram[i]++;
                }
            }
            ans = max(ans, maximalRectangleUtil(histogram));
        }
        return ans;
    }
};



class Solution_BruteForce {
private:
    void getLeftBound(vector<int> &histogram, int n, vector<int> &leftBound) {
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && histogram[st.top()] >= histogram[i]) {
                st.pop();
            }
            if(st.empty()) leftBound[i] = 0;
            else leftBound[i] = st.top()+1;
            st.push(i);
        }
    }

    void getRightBound(vector<int> &histogram, int n, vector<int> &rightBound) {
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && histogram[st.top()] >= histogram[i]) {
                st.pop();
            }
            if(st.empty()) rightBound[i] = n-1;
            else rightBound[i] = st.top()-1;
            st.push(i);
        }
    }

    int maximalRectangleUtil(vector<int> &histogram, int n) {
        vector<int> leftBound(n);
        vector<int> rightBound(n);
        getLeftBound(histogram, n, leftBound);
        getRightBound(histogram, n, rightBound);
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, histogram[i] * (rightBound[i] - leftBound[i] + 1));
        }
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> histogram(n, 0);
        int ans = 0;
        for(auto it: matrix) {
            for(int i=0; i<n; i++) {
                if(it[i] == '0') {
                    histogram[i] = 0;
                }
                else {
                    histogram[i]++;
                }
            }
            ans = max(ans, maximalRectangleUtil(histogram, n));
        }
        return ans;
    }
};