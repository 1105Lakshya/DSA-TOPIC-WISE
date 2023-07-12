/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int size= s.size(),i=0,ans=0;
        char prevOperator='+';
        stack<int> sta;
        while(i<size){
            if(s[i]==' '){
                i++;
                continue;
            }
            int num=0;
            while(isdigit(s[i]))
                num = num*10 + (s[i++]-'0');
            if(prevOperator=='+')
                sta.push(num);
            else if(prevOperator=='-')
                sta.push(-num);
            else if(prevOperator=='*'){
                int x=sta.top();
                sta.pop();
                sta.push(x*num);
            }
            else if(prevOperator=='/'){
                int x=sta.top();
                sta.pop();
                sta.push(x/num);
            }
            prevOperator=s[i++];
        }
        while(sta.size()){
            ans+=sta.top();
            sta.pop();
        }
        return ans;
    }
};




int main(){
    
    return 0;
}