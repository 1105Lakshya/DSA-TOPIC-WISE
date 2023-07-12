/*
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

 

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
Example 3:

Input: s1 = "a", s2 = "a"
Output: true
 

Constraints:

s1.length == s2.length
1 <= s1.length <= 30
s1 and s2 consist of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    unordered_map<string,bool> dp;
    bool solve(string s1, string s2 ){
        if(s1==s2)return true;


        int arr[26]={0};
        int len=s1.length();
        for(int i=0; i< len;i++){
            arr[s1[i]-'a']++;
            arr[s2[i]-'a']--;
        }

        for(int i=0 ;i< 26;i++){
            if(arr[i]!=0){
                return false;
            }
        }

        string str=s1+"#"+s2;
        if(dp.find(str)!=dp.end())return dp[str];




    for(int i=1 ;i< len ;i++){
        bool noswap=solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i),s2.substr(i));
        if(noswap){
            dp[str]=true;
            return true;
        }
        

        bool swap=solve(s1.substr(0,len-i),s2.substr(i))&& solve(s1.substr(len-i),s2.substr(0,i));
        if(swap){
        dp[str]=true;
        return true;            
        }



        }
        
        dp[str]=false;
        return false;
    }
public:
    bool isScramble(string s1, string s2) {

        return solve(s1,s2);
        
    }
};

int main(){
    
    return 0;
}