#include<iostream>
#include<vector>

using namespace std;

string read(int n, vector<int> book, int target)
{
    // Write your code here.
    sort(book.begin(), book.end());
    int i = 0;
    int j = book.size()-1;
    while(i < j) {
        if(book[i]+book[j] == target) return "YES";
        else if(book[i]+book[j] < target) i++;
        else j--;
    }
    return "NO";
}
