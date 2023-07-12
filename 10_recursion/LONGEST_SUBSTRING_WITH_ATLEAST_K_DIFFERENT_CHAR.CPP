/*

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105




*/





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

int longestSubstring(string s, int k) {
    int n = s.size();
    if(n<k) return 0;
    unordered_map<char,int>m;
    for(auto x:s){
        m[x]++;
    }
    int j = 0;
    while(j<n && m[s[j]]>=k) j++;
    if(j>=n-1) return j;
    int c1 = longestSubstring(s.substr(0,j),k);             // jo string ayyii hai usmeii jarrorii ni hai ki saree character atleas k times present homggee toh uss ko bhi kahaa gandu answer nikal ke laaa
    while(j<n && m[s[j]]<k) j++;
    int c2 = longestSubstring(s.substr(j),k);                   //bacchi hui string mei se answer mikal laoooooo
    return max(c1,c2);
}
};


int main(){
    
    return 0;
}