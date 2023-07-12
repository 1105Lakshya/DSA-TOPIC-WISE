



#include<stack>
#include<bits/stdc++.h>
using namespace std;


class SpecialStack {
    // Define the data members.
	stack<int> s;
	int mini;
	
    //----------------- Public Functions of SpecialStack -----------------//
    public:
        
    void push(int data) {
	//for first element 
		if(s.empty ()){
			s.push(data);
			mini=data;
		}
		else{
			if(data<mini){
				int val=2*data-mini;  //formula yaad rakhna haii
				s.push(val);
				mini=data;
			}
			else{
				s.push(data);
			}
		}
	}

    int pop() {
if(s.empty ()){
	return -1;
}
		int curr=s.top();
		s.pop();
		if(curr>mini){
			return curr;
		}
		else{                     //agar uppar walli condition nahhi hai iska matllab humara yahh pr mini change huua tha toh puranne walle mini jo neeche walli stack ka tha usko restore krnna padeggaa formulae seee
			int prevmin=mini;
			int val=2*mini-curr;
			mini=val;
			return prevmin;
		}
	}

    int top() {
	if(s.empty ()){
		return  -1;
	}   
		int curr=s.top();
		if(curr<mini){
			return mini;
		}
		else{
			return curr;
		}
	
	}

    bool isEmpty() {
return s.empty();
	}

    int getMin() {
		if(s.empty())
			return -1;
		return mini;
    }  
};






