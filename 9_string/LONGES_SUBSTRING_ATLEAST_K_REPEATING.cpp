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
private:
public:
    int longestSubstring(string s, int k) {
        if(s.size()<k  ){       // in this case no possible string exist
            return 0; 
        }
        if(k==1){
            return s.size();  // in this case whole string will be the required string
        }
        int n=s.size();
        unordered_map<char,int> count;
        for(auto str:s){
            count[str]++;
        }
    int j = 0;
    while(j<n && count[s[j]]>=k) j++;
        
    if(j>=n-1) return j;
        
    int c1 = longestSubstring(s.substr(0,j),k);
        
    while(j<n && count[s[j]]<k) j++;
        
    int c2 = longestSubstring(s.substr(j),k);
        
    return max(c1,c2);
        
    }
};



int main(){
    
    return 0;
}