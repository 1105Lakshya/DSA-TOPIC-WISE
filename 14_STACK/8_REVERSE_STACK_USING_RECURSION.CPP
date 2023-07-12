#include<bits/stdc++.h>
using namespace std;

//function to insert at bottom of the stack

void solve(stack<int>& myStack, int x){
	if(myStack.empty()){
		myStack.push(x);
		return ;
	}
	int num=myStack.top();
	myStack.pop();
	solve(myStack,x);
	myStack.push(num);
	return;
	
}


void InsertAtBottom(stack<int> &myStack,int x)
{
	solve(myStack,x);
}




void reverseStack(stack<int> &stack) {
	//base case
	if(stack.empty())
		return;
	
	int num=stack.top();//element side mei nikal ke rakhliyyaaa
	stack.pop();
	reverseStack(stack);  // bacche huee stack ko reverse krraliyyyaa
	InsertAtBottom(stack, num);       //element ko bottom mei insert krdiyyyyaaa
	return;                    // return krdiyyyyaaaaaaaaaaaaaaa

}

int main(){
    
    return 0;
}