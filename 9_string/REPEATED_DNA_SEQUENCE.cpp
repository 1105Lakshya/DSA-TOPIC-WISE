/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.
*/



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i=0;
        vector<string> ans;
        unordered_set<string> vis;
        unordered_set<string> res;

        vis.insert(s.substr(i,10));
        i++;
        int len=s.size();
        while(i+9< len){
            string temp=s.substr(i,10);
            
            if(res.find(temp)!=res.end()){
                i++;
                continue;
            }
            else{
                if(vis.find(temp)!=vis.end()){
                    res.insert(temp);
                    ans.push_back(temp);
                    i++;
                }
                else{
                    vis.insert(temp);
                    i++;
                }
            }
        }
return ans;
    }
};








int main(){
    
    return 0;
}