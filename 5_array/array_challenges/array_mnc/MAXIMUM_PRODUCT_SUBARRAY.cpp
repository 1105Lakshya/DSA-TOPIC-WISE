/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/


//just like kadane  
//to handle negative  just do traversal from starting and then from end   negative walla handel hojayyegaa thoda soch ke samjha ajjega aisa kyu horra 
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currproduct=1;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            currproduct*=nums[i];
            if(currproduct==0){
                currproduct=1;
                continue;
            }
            ans=max(ans,currproduct);
        }
        if(ans<0){
            return 0;
        }
        currproduct=1;
        for(int i=n-1;i>=0;i--){
            currproduct*=nums[i];
            if(currproduct==0){
                currproduct=1;
                continue;
            }
            ans=max(ans,currproduct);
        }
        
    if(ans==0){
         ans=nums[0];
        for(int i=1;i<n;i++){
            ans=max(ans,ans*nums[i]);
        }
    }
        return ans;
    }
};


int main(){
    
    return 0;
}