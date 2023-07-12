#include<bits/stdc++.h>
using namespace std;

//ek uppar se bhar re ek neeche se array meeiiii

class TwoStack {

public:

    // Initialize TwoStack.
	int *arr;
	int top1;
	int top2;
	int size;
	
    TwoStack(int s) {
        this-> size =s;
		arr=new int[s];
		top1=-1;
		top2=s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2 - top1 >1){
			top1++;
			arr[top1]=num;
		}
		else{
			cout<< "Stack Overflow"<<endl;
		}
		// Write your code here.
    }

    // Push in stack 2.
    void push2(int num) {
		    if(top2 - top1 >1){
			top2--;
			arr[top2]=num;
		}
		else{
			cout<< "Stack Overflow"<<endl;
		}
        // Write your code here.
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
		if(top1 >=0){
			int ans=arr[top1];
			top1--;
			return ans;
		}
		else{
			cout<< "Stack Underflow" <<endl;
			return -1;
		}
        // Write your code here.
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
				if(top2<size){
			int ans=arr[top2];
			top2++;
			return ans;
		}
		else{
			cout<< "Stack Underflow" <<endl;
			return -1;
		}
        // Write your code here.
    }

};





int main(){
    
    return 0;
}