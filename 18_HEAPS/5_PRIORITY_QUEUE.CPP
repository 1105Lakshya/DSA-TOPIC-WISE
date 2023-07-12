#include<bits/stdc++.h>
using namespace std;

int main(){

    //STL MAXHEAP
    priority_queue<int> pq;
    pq.push(1);
    pq.push(4);
    pq.push(5);
    pq.push(3);
    pq.push(11);
    pq.push(1);

    cout<< "element at top "<< pq.top()<<endl;
    pq.pop();
    cout<< "element at top "<< pq.top()<<endl;
    pq.pop();
    cout<< "element at top "<< pq.top()<<endl;
    pq.pop();
    cout<< "element at top "<< pq.top()<<endl;
    pq.pop();
    cout<< "element at top "<< pq.top()<<endl;
    pq.pop();
    cout<< "element at top "<< pq.top()<<endl;


    cout<<"size is : "<<pq.size()<<endl;

    //Min heap

    priority_queue<  int ,vector<int> ,greater<int>  >  minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(3);
    minheap.push(1);


    cout<< "element at top of minheap "<< minheap.top()<<endl;
    minheap.pop();
    cout<< "element at top of minheap"<< minheap.top()<<endl;
    minheap.pop();
    cout<< "element at top of minheap"<< minheap.top()<<endl;
    minheap.pop();
    return 0;
}