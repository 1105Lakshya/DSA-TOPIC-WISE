/*


Greatest Common Divisor of Strings
Easy
3.7K
634
Companies
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.




*/
#include<bits/stdc++.h>
using namespace std;


class Solution {

    int get_gcd(int a,int b){
while(a!=0  && b!=0){
    if(a>=b)
    {
        a=a%b;
    }
    else
    {
        b=b%a;
    }
}


if (a==0){
    return b;
}
if(b==0){
    return a;
}
return 1;
}

public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1){
            return "";
        }
        return str2.substr(0,get_gcd(str1.length(),str2.length()));

    }
};