#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(11);
    cout<<"front of q is "<<q.front()<<endl;
    q.push(12);
    cout<<"front of q is "<<q.front()<<endl;
    q.push(13);
    cout<<"front of q is "<<q.front()<<endl;

    cout<<"size of queue is"<<" "<< q.size()<<endl;
    q.pop();

    cout<<"size of queue is"<<" "<< q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty "<<endl;
    }
    else{
        cout<<"queue is not empty "<<endl;
    }
    
    return 0;
}