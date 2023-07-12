/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==0)return num;
        int n=num.size();
        if(k==n)return "0";
        string ans="";
        ans+=num[0];
        for(int i=1;i<n;i++){
            if(k!=0 && (ans!="" && ans.back()>num[i] )){
                ans.pop_back();
                k--;
                i--;
                continue;
            } 
    ans+=num[i];
        }
        
        
        n=ans.size();
        if(k>0 && n>=2){
        if(ans[n-1]<ans[n-2]){
            char c= ans.back();
            ans.pop_back();
            while(k){
                ans.pop_back();
                k--;
            }
            ans+=c;
        }
        else{
            while(k){
                ans.pop_back();
                k--;
            }
        }
        }
        
         
        while(ans[0]=='0'){
            ans.erase(0,1);
        }
        
        if(ans=="")return "0";
        return ans;
    }
};


int main(){
    
    return 0;
}