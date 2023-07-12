/*
Given two strings s and t, return the number of distinct 
subsequences
 of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/


#include<bits/stdc++.h>
using namespace std;



class Solution {
    int solve(int i , int j , string &s , string &t , vector<vector<int>>& dp){
        int n=s.size();
        int m=t.size();
        if(j>=m){
            return 1;
        }
        if(i>=n)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
            int ans=0 ;        
        if(s[i]==t[j]){
            ans+=solve(i+1, j+1, s ,t,dp);
        }
        
        ans+=solve(i+1,j ,s , t,dp);
        
        
        dp[i][j]=ans;
        return ans;      
        
    }
    
    
    
public:
    int numDistinct(string s, string t) {
        int i=0 ;
        int j=0 ;
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        
        return solve(0,0,s,t,dp);
    }
};

int main(){
    
    return 0;
}