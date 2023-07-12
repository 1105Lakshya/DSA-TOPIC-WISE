/*

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/


//make a stack of star and open brackets and store their indexes 
//when a close brac comes pop from open brac if couldnot pop from star else return false
//in the end the left open brackets will be compensated by star that occur above their addresss

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> brac;

        stack<int> star;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(brac.empty() && star.empty())return false;
                if(brac.empty())star.pop();
                else brac.pop();
            }
            else if(s[i]=='('){
                brac.push(i);
            }
            else{
                star.push(i);
            }
        }

        while(!star.empty() && !brac.empty() && brac.top()<star.top()){
            brac.pop();
            star.pop();
        }



        return brac.empty();

    }
};