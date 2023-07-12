#include<bits/stdc++.h>
using namespace std;

class kQueue{
    private:
    int *arr;
    int *next;
    int* front;
    int* rear;
    int size;
    int queues;
    int freespot;
    
    public:
    
    kQueue(int n , int k){
        this->size=n;
        this->queues=k;
        front=new int[k];
        rear=new int[k];

        for(int i=0;i<k ;i++){
            front[i]=-1;
            rear[i]=-1;
        }

        arr=new int[size];
        next=new int[size];
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        freespot =0;
    }

    void enqueue(int data, int qn){
        //checking if free space is available to enqueue orr not
        if(freespot==-1){
            cout<<" Deepika  ke pass or jagggaa ni haiii . "<<  endl;
            return ;
        }
        //find first free spave
        int index=freespot;

        //update freespot
        freespot=next[index];

        // check weather first element  is inserted
        if(front[qn-1]==-1){
            front[qn-1] =index;
        }
        else{
            // link new element to prev element 
            next[rear[qn-1]]=index;
        }
        // update next
        next[index]=-1;
         
        //update rear
        rear[qn-1]=index;

        //push element 
        arr[index]=data;
    }


    int  dequeue ( int qn){
        //under flow 
        if(front[qn-1]==-1){
            cout<< " khaaalii hai merre dost queue already us se kya nikaleggaa"<<endl;
        return -1;
        }

        //find index too pop
        int index =front[qn-1];

        //front ko agge bhadaoooo
        front[qn-1]=next[index];

        //freeslots ko manage karroo
        next[index]=freespot; // jis index se pop hoogga whaa free spot banjaayega toh free spot ko index se update krdengge or next[index] mei jo current freespot thaa woh daadenggee
        freespot=index;
        return arr[index];
    }    



};


int main(){

    kQueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout<<"q1.dequeqe:"<<q.dequeue(1)<<endl;
    cout<<"q2.dequeqe:"<<q.dequeue(2)<<endl;
    cout<<"q1.dequeqe:"<<q.dequeue(1)<<endl;
    cout<<"q1.dequeqe:"<<q.dequeue(1)<<endl;


    cout<<"q1.dequeqe:"<<q.dequeue(1)<<endl;

    
    return 0;
}