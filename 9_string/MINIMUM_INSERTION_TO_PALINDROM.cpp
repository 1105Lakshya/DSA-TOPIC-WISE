/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int solve(int i ,int j ,string &s,vector<vector<int>> &dp){

        //palindrome commpleted no more additions requiredd  
        if(i>=j)return 0;


        if(dp[i][j]!=-1)return dp[i][j];

        
        //if s[i]==s[j] then no need to add anythingg 

        if(s[i]==s[j]){
        dp[i][j]=solve(i+1,j-1,s,dp);    
        return dp[i][j];
        }

        //if they do not match then either add the left character or the right character 

        //left one is added in the palindrom so moved i
        int option1=solve(i+1,j,s,dp);


        //right character is added in the left part to make palindrome so moved left 
        int option2=solve(i,j-1,s,dp);


        dp[i][j]=1+min(option1,option2);

        return dp[i][j];

    }

    int solveTab(string &s){
        int n=s.size();

        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for(int len=1;len<n;len++){
            for(int i=0;i+len<n;i++){
                if(s[i]==s[i+len])dp[i][i+len]=dp[i+1][i+len-1];
                else dp[i][i+len]=1+min(dp[i+1][i+len],dp[i][i+len-1]);
            }
        }

        return dp[0][n-1];
    }


    
public:
    int minInsertions(string s) {

        // int n=s.size();

        // vector<vector<int>> dp(n,vector<int>(n,-1));

        // return solve(0,n-1,s,dp);


        return solveTab(s);
        
    }
};

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}