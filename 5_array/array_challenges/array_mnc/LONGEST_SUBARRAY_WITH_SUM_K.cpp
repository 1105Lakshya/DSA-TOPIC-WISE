/*

Given an array arr containing n integers and an integer k. Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.

 

Examples:
 

Input :
arr[] = {10, 5, 2, 7, 1, 9}, k = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Input : 
arr[] = {-1, 2, 3}, k = 6
Output : 0
Explanation: 
There is no such sub-array with sum 6.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

 

Constraints:
1<=n<=105
-105<=arr[i], K<=105



*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        unordered_map<int,int> mp;//to store prefix sum 
        mp[0]=-1;
        int sum=0;
        int maxlen=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int req=sum-k; //if req exist in mp then it means we have a subarray with sum k
            
            if(mp.find(req)!=mp.end()){
                maxlen=max(maxlen,i-mp[req]);
            }
            
            if(mp.find(sum)==mp.end()){  //since we want longest subarraay 
                mp[sum]=i;
            }
        }
        
        
        return maxlen;
        
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends