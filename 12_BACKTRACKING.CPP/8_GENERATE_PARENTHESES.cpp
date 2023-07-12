/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

#include <vector>
#include <iostream>
using namespace std;


class Solution {
    vector<string> ans;
    int n;
    void solve( int open , int close ,string &output)
    {
        if(open ==n && close==n){
            ans.push_back(output);
            return ;
        }


        if(open<n){
            output+='(';
            solve(open+1,close,output);
            output.pop_back();
        }

        if(close<open){
            output+=')';
            solve(open , close+1,output);
            output.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int N) {
        n=N;
        if(n==1)return {"()"};
        string output="";
        solve(0,0,output);

        return ans;
    }
};