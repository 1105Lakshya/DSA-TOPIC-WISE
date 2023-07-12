#include<bits/stdc++.h>
using namespace std;

//implement dequeue  code studio

int main(){
    deque<int>  d;
    d.push_front(12);
    d.push_back(99);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_front();

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    
    d.pop_back();

    if(d.empty()){
        cout<<"deepika tenu ni krdaa pyaar soniyyee"<<endl;
    }
    return 0;
}