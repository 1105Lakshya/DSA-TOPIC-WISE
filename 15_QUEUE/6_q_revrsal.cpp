/*

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{  
 //****************** approach 1 using stack***********************
   
   
   
    int n=q.size();
stack<int> s;
for(int i=0;i<n ;i++){
    s.push(q.front());
    q.pop();
}
for(int i=0;i<n;i++){
    q.push(s.top());
    s.pop();
}
return q;
}




*/

//RECURSIVE ALGOOOOOO

/*

void reverse(queue<int>& q){
    if(q.empty()){
        return;
    }
    
    int n=q.front();
    q.pop();
    reverse(q);
    q.push(n);
    return;
}

queue<int> rev(queue<int> q)
{
//******************APPROACH 2 USING RECURSION*********************
reverse(q);
return q;
}


*/


