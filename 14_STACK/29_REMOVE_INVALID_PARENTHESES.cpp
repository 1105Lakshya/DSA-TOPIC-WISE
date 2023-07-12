/*

01. Remove Invalid Parentheses
Hard
5.5K
264
Companies
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]
 

Constraints:

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
bool isvalid(string s){
    
    int n=s.size();
    if(n==0)
        return true;
    stack<char> stack;
    for(int i=0 ;i< n;i++){
        char c=s[i];
        if(c=='('){
            stack.push('(');
        }
        else if(c==')'){
            if(stack.empty() || stack.top()==')')
                return false;
            else
                stack.pop();
      }
        else{
            if(stack.empty() || stack.top()=='(')
                continue;
            else
                return false;
        }
    }   
    return stack.empty();
}
    
    
void solve(string s ,int index,int min_par ,unordered_set<string> &set)  {
    if(min_par==0  ){
        if(isvalid(s))
        set.insert(s);
        return ;
    }
    if(index>=s.size())
        return ;
         
    
    while(s.size()>index){
        char temp=s[index];
        if(temp=='(' || temp==')'){
        s.erase(index,1);
        
        solve(s , index , min_par-1 ,set);
        
        if(temp==')')
        s.insert(index,")");
        else
        s.insert(index,"(");
        }
        index++;
    }
}  
public:
    vector<string> removeInvalidParentheses(string s) {
       int n=s.size();
       stack<char> stack;
        for(int i=0 ;i< n;i++){
            char c=s[i];
            if(c=='('){
                stack.push('(');
                    
            }
            else if(c==')'){
                if(!stack.empty()&& stack.top()=='(')
                stack.pop();
                else
                stack.push(')');
            }
        }
        vector<string> ans;
        
      int min_par=stack.size();
        unordered_set<string> set;
    solve(s ,0, min_par , set);
        for(auto it: set){
            ans.push_back(it);
        }
        return ans;
    }
};



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}