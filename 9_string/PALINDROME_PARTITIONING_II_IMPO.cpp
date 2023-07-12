/*

Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​

A string is said to be palindrome if it the same string when reversed.

 

Example 1:

Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
Example 2:

Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.
 

Constraints:

3 <= s.length <= 2000
s​​​​​​ consists only of lowercase English letters.

*/



//ismei hum do pointer select karte haii and then teen regions ko palindrome check karte haii ab constraint ke hisab se humara solution n2 hona chhiyye but comparison mei n3 hojaegga toh hum preprocess karke rakhengee taki humme ekdum se milljayye ki do index ke beech mei jo string hai wo palindrome hai ke niii

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>>isPalindrome;
    void preProcess(string s)
    {
        int n=s.size();
        isPalindrome.resize(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            isPalindrome[i][i]=1;
            if(i+1<n && s[i]==s[i+1])isPalindrome[i][i+1]=1;
        }
        for(int len=3;len<n;len++)
        {
            for(int i=0;i<n;i++)
            {
                int j=i+len-1;
                if(i<n && j<n && i+1<n && j-1<n && isPalindrome[i+1][j-1]==1 && s[i]==s[j])
                {
                    isPalindrome[i][j]=1;
                    isPalindrome[j][i]=1;
                }
            }
        }

    }//o(n^2)
    bool checkPartitioning(string s) {
        preProcess(s);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int left=0, right=0;
                int leftL=0,leftR=i-1;
                int rightL=j+1,rightR=n-1;
                if(leftL<=leftR && leftR<i && rightL>j && rightL<=rightR && isPalindrome[leftL][leftR]==1 && isPalindrome[i][j]==1 && isPalindrome[rightL][rightR]==1) return 1;
            }
        }//O(n^2)
        return 0;
    }
};