#include<bits/stdc++.h>
using namespace std;

// squr(n) time complexity

void InsertSorted(stack<int> &stack, int x){
    //base case
	if(stack.empty()){
		stack.push(x);
		return;
	}
	if(stack.top()<x){
		stack.push(x);
		return;
	}


	int num=stack.top();  //shurat walla bachha ke rakhhaa
	stack.pop();
	InsertSorted(stack, x);      //bakki mei insert sorted krdiyya
	stack.push(num);           //jatte huee element ko lejattta hua challagyyaa
	return ;
}




void sortStack(stack<int> &stack)
	//base case
{	if(stack.empty()){
	return;
}

    
    int num=stack.top();   //pehla element uthha liyyyaaa
    stack.pop();             
    sortStack(stack);            //bacche hue stack ko sort krdiyyaaa
    InsertSorted(stack,num);     //jo bachha ke rakhha tha element usko sorted way mei insert krdiya
 	return;
}


int main(){
    
    return 0;
}