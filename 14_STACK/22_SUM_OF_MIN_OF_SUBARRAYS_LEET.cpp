/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]   
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/






#include<bits/stdc++.h>
using namespace std;


#define MOD 1000000007
class Solution {
    void next_smaller(vector<int>& arr, vector<int> &next){
        int n=arr.size();
        stack<int> st;
        st.push(n-1);
        next[n-1]=n-1;
        for(int i=n-2;i>=0 ;i--){
            if(arr[i]> arr[st.top()]){
                next[i]=i;
                st.push(i);
            }
            else{
                while(!st.empty() and arr[i]<=arr[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    next[i]=n-1;
                    st.push(i);
                }
                else{
                    next[i]=st.top() - 1;
                    st.push(i);
                }
            }
        }
    }
    
    void prev_smaller(vector<int>& arr, vector<int> &prev){
        int n=arr.size();
        stack<int> st;
        st.push(0);
        prev[0]=0;
        for(int i=1;i<n ;i++){
            if(arr[i]>= arr[st.top()]){
                prev[i]=i;
                st.push(i);
            }
            else{
                while(!st.empty() and arr[i]<arr[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    prev[i]= 0;
                    st.push(i);
                }
                else{
                    prev[i]=st.top() + 1;
                    st.push(i);
                }
            }
        }
    }
    
    
    
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
    vector<int> next(n ,0);
    vector<int> prev(n,0);
    
    next_smaller(arr ,next);
    prev_smaller(arr ,prev);
        int ans=0;
        
    for(int i=0 ;i<n;i++){
        long long int  prod=(next[i]-prev[i]+1 +((next[i] - i)*(i-prev[i])))%MOD;
        
            prod = (prod*arr[i])%MOD;
            ans = (ans + prod)%MOD;
    }
        
        return ans%MOD;
    }
};




int main(){
    
    return 0;
}