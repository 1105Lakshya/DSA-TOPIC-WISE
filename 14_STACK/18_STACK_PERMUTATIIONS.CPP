/*

A stack permutation is a permutation of objects in the given input queue which is done by transferring elements from input queue to the output queue with the help of a stack and the built-in push and pop functions.
The well defined rules are: 
 

1. Only dequeue from the input queue.
2. Use inbuilt push, pop functions in the single stack.
3. Stack and input queue must be empty at the end.
4. Only enqueue to the output queue.



*/




// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
    queue<int> input;
    for(int i=0;i<N;i++){
        input.push(A[i]);
    }
    int j=0;
    stack<int> s;
    while(j<N){
        while(input.front()!=B[j]  && !input.empty()){
            s.push(input.front());
            input.pop();
        }
        if(!input.empty())
        input.pop();
        j++;
        
        
        while(!s.empty() && B[j]==s.top() && j<N){
            s.pop();
            j++;
        }
    }
    
    if(input.empty() && s.empty()){
        return 1;
    }
    else{
        return 0;
    }
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends