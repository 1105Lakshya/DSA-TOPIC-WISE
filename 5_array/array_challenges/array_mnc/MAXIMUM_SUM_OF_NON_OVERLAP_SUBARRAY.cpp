/*
Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.

The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
Example 2:

Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
Example 3:

Input: nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3.
 

Constraints:

1 <= firstLen, secondLen <= 1000
2 <= firstLen + secondLen <= 1000
firstLen + secondLen <= nums.length <= 1000
0 <= nums[i] <= 1000
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {


    int solve(int x, int y , vector<int>&nums){
        int n=nums.size();
        int arr[n]; //use to store maximum  sum up to this index from starting

        int i=0;
        int j=0;
        int sum=0;

        while(j<x){
            sum+=nums[j++];
        }
        
        arr[x-1]=sum;

        while(j<n){
            sum-=nums[i++];
            sum+=nums[j];
            arr[j]=max(sum,arr[j-1]);
            j++;
        }

        sum=0;

        int brr[n];// use to store the max sum up to this index from ending 

        i=n-1;
        j=n-1;
        sum=0;
        int loda=y;
        while(loda--){
            sum+=nums[j--];
        }
        
        brr[n-y]=sum;

        while(j>=0){
            sum-=nums[i--];
            sum+=nums[j];
            brr[j]=max(sum,brr[j+1]);
            j--;
        } 

        int end=n-y;
        int ans=0;


        //use to get answer by starting se firstlen ka answer and ending array mei secondlen ka max sum or unka sum or fir take max
    for(int t=x-1 ; t< end ;t++){
        int temp=arr[t]+brr[t+1];
        ans=max(ans,temp);
    }

return ans;
    }

public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        int ans1=solve(firstLen , secondLen , nums);  //shuruatt part mei array ke firstlen walli array or baddmei secondlen

        int ans2=solve(secondLen ,firstLen ,nums);    //shuruatt part mei array ke secondlen walli array or baddmei firstlen

        return max(ans1, ans2);

    }
};








int main(){
    
    return 0;
}

        
