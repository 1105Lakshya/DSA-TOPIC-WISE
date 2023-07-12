#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
	int *arr;
	int front;
	int rear;
	int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
	    size=n;
		arr=new int [size];
		front=-1;
		rear=-1;
	}

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
	if((front==0 && rear==size-1 ) || (rear==(front-1)%(size-1))){     //condition ratt le mere bhaii   //second walli condition ka matlab haii ki rear jo hai wo front ke just peeche haiii
		//cout<<"Queue is full"<<endl;
		return false;
	}
	if(front==-1){  //first element to push
		front=0;
		rear=0;
	}
	else if(rear==size-1 && front!=0){
		rear=0;
	}
	else{
			rear++;            // normal case
	    }
		
		arr[rear]=value;     
		
		return true;
	}

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
		if(front==-1 && rear==-1 ){
			return  -1;
		}
		
		int ans=arr[front];
		arr[front]=-1;

		if(front==rear){  // single element present in queue so after poping queue will become empty 
		front=-1;
		rear=-1;
	}
		else if(front==size-1){    //to maintain cyclic nature
		front=0;
		}
		else{                  //normal pop 
			front++;
		}
		return ans;
    }
};




int main(){
	CircularQueue  q(5);
	bool a=q.enqueue(1);
	bool a=q.enqueue(2);
	bool a=q.enqueue(3);
	bool a=q.enqueue(4);
	bool a=q.enqueue(5);

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();

    
    return 0;
}