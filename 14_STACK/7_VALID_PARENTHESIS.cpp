/*


Problem Statement
You're given string ‘STR’ consisting solely of “{“, “}”, “(“, “)”, “[“ and “]” . Determine whether the parentheses are balanced.
Input Format:
The first line contains an Integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of input of each test case contains a string, as described in the task.
Output Format :
For each test case, the first and the only line of output prints whether the string or expression is balanced or not.

The output of every test case is printed in a separate line.
Note:
You are not required to print anything explicitly. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10^5

Where N is the length of the input string or expression.

Time Limit: 1 sec
Sample Input 1 :
2
[()]{}{[()()]()}
[(])
Sample Output 1 :
Balanced
Not Balanced
Explanation Of The Sample Input 1 :
In TestCase 1 there is always an opening brace before a closing brace i.e ‘{‘ before ‘}’, ‘(‘ before ‘)’, ‘[‘ before ‘]’.

In TestCase 2 there is closing brace for ‘[‘ i.e. ‘]’ before closing brace for ‘(‘ i.e. ‘)’. The balanced sequence should be ‘[()]’.
Sample Input 2 :
2
[[}[
[]{}()
Sample Output 2 :
Not Balanced
Balanced
Explanation Of The Sample Input 2 :
In TestCase 1 there is no opening brace before a closing brace i.e no ‘{‘ for ‘}’.

In TestCase 2 there is exactly one closing for each opening braces and each closing brace is after their corresponding opening brace.



*/





#include<bits/stdc++.h>
using namespace std;


#include<stack>

bool matches(char ch1, char ch2){
	if(ch1=='{'  && ch2== '}')
		return true;
	if(ch1=='['  && ch2== ']')
		return true;
	if(ch1=='('  && ch2== ')')
		return true;
	else
		return false;
}


bool isValidParenthesis(string str)
{// if opening bracket stack push
// if closing bracket stack top check and pop
	stack<char> s;
	for(int i=0;i<str.size();i++){
		char ch=str[i];
		if(ch=='{'  || ch=='[' ||  ch=='('){
			s.push(ch);
		}
		else{
			if(!s.empty()){
				if(matches(s.top(),ch)){
				s.pop();
				continue;
			}
			else{
				return false;
			}
			}
			else{
				return false;
			}
			
		}
	}


if(s.empty()){
	return true;
}
	else{
		return false;
	}

}


int main(){
    
    return 0;
}