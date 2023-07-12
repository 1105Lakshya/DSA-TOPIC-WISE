#include<bits/stdc++.h>
using namespace std;


class Queue {
	int *arr;
	int qfront ;
	int rear;
	int size;
public:
    Queue(int size) {
	this->size=size;
	arr=new int[size];
	qfront =0;
	rear=0;
	}

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
	if(qfront==rear){
		return true;
	}
	else{
		return false;
	}
	}

    void enqueue(int data) {    //jis index pe hotta hai uspe value daal detta hai or fir agle index pr jumpe kr jatta haii
	if(rear==size){
		cout<<"Queue is full"<<endl;
	}
	else{
		arr[rear]=data;
		rear++;
	}
	}

    int dequeue() {
        if(qfront==rear){
			return -1;
		}
		else{
			int ans=arr[qfront];
			arr[qfront]=-1;
			qfront++;
			if(qfront==rear){   //agar front =rear matlab queue khaali toh front or rear ko starting mei bhejjdooo
				qfront=0;
				rear=0;
			}
			return ans;
		}
    }

    int front() {
	if(qfront == rear){
		return -1;
	}
		else{
			return arr[qfront];
		}
	}
};




int main(){
    
    return 0;
}