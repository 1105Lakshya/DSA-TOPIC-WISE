/*
A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

If locked[i] is '1', you cannot change s[i].
But if locked[i] is '0', you can change s[i] to either '(' or ')'.
Return true if you can make s a valid parentheses string. Otherwise, return false.

 

Example 1:


Input: s = "))()))", locked = "010100"
Output: true
Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.
Example 2:

Input: s = "()()", locked = "0000"
Output: true
Explanation: We do not need to make any changes because s is already valid.
Example 3:

Input: s = ")", locked = "0"
Output: false
Explanation: locked permits us to change s[0]. 
Changing s[0] to either '(' or ')' will not make s valid.
 

Constraints:

n == s.length == locked.length
1 <= n <= 105
s[i] is either '(' or ')'.
locked[i] is either '0' or '1'.

*/






/*
Intuition :

Idea :
Idea is similar to other Balance Parentheses related problems. i.e we check the balance of ( and ) brackets.

And whenever number of ) exceeds number of ( , we can say that it is unbalanced from start.

And whenever number of ( exceeds number of ) , we can say that it is unbalanced from end ( this one is trivial).

This can be done by incrementing when we see opening ( bracket and decrementing vice versa.

Observations :
We can get a valid Balanced Parentheses only when length of string is even.

So that every ( bracket has it counterpart ).
String can be said invalid in terms of ( , if

number of ) > number of ( , at any point.
and vice versa in terms of ) as well.
Also in this problem, we are given that we can change bracket at index i

iff locked[i] == '0' , i.e index i is unlocked
Thus, we can say if at point we see balance < 0, but that index is unlocked,

then we change character at that index, thus maintaining the balance.
So we need to check if string is balanced in terms of opening '(' bracket from left -> right.
As well as check if string is balanced in terms of closing ')' bracket from right -> left.
If at any point we encounter negative balance i.e balance < 0 , simple return false as it is surely invalid.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
    
        int n = s.size();
        if(n&1) return false;
         
        int balance = 0;
        
		// First check balance from left to right
		// For opening '(' brackets
		
        for(int i=0; i<n; i++) {
		
			// If either char is ( or it is unlocked,  
			// We can increment balance
			
            if(locked[i] == '0' || s[i] == '(') balance++;   
            else balance--;     // otherwise decrement balance, since it is ) and also locked
            
			// Since balance is negative, we have more ')'. 
			// And there is no unlocked char available
			// SO, it is invalid string for sure
			
            if(balance < 0) return false;
        }
        
		// reset balance 
        balance = 0;
		
		// Then also check balance from right to left
		// For closing ')' brackets

        for(int i=n-1; i>=0; i--) {
		
			// If either char is ) or it is unlocked,  
			// We can increment balance
			
            if(locked[i] == '0' || s[i] == ')') balance++;
            else balance--;
            
			// Since balance is negative, we have more '('. 
			// And there is no unlocked char available
			// SO, it is invalid string for sure
			
            if(balance < 0) return false;
        }
        
        return true;
    }
};









int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}