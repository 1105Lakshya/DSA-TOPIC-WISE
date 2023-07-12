/*

Companies
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
 

Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].


*/


/*
class Solution {
    int n;
    int target;
    int total;
    int k;
    vector<int> arr;


    bool solve(int index, vector<int> &nums){
        int k=arr.size();

        if(index==n){
            for(int i=1;i<k;i++){
                if(arr[i]!=arr[0])return false;
            }
            return true;
        }

        //set keeps track of the numbers in which we have added our index and asked to solve furthur
        //suppose intitallly  arr is 0 0 0 0 0 0 so now it does not make sense to add my current index to each 0 individually one time is perfect this will cut a lot of branch 
        unordered_set<int> st;
        

        for(int i=0;i<k;i++){
            if(st.find(arr[i])!=st.end()){
            st.insert(arr[i]);
            arr[i]+=nums[index]; 
            bool ans=solve(index-1,nums);
            if(ans)return true;
            arr[i]-=nums[index];  

            }
            
        }


        return false;
    }

    
public:
    bool canPartitionKSubsets(vector<int>& nums, int K) {
        k=K;

        total=accumulate(nums.begin(),nums.end(),0);

        target=total/k;

        if(total%k!=0)return false;

        //sorting the nums and starting from back is good as it will start filling the arr with greater numbers first so there will be much less time wasted 
        sort(nums.begin(),nums.end());


        n=nums.size();
        arr.resize(k,0);

        //starting from the end so that 
        return solve(n-1,nums);

    }
};

*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    unordered_map<int,unordered_map<int,bool>> dp;
    int target;
    int n;
    public:

    bool solve(int mask,int left ,vector<int> &nums ){
        int goal=pow(2,n)-1;


        // if all get masked return true 
        if(mask==goal)return true;


        // if left=0 then reinitalize it to target 
        
        if(left==0)left=target;


        if(dp.find(left)!=dp.end()){
            if(dp[left].find(mask)!=dp[left].end()){
                return dp[left][mask];
            }
        }



        for(int i=0;i<n;i++){
            if(!(mask & (1<<i))  &&  left-nums[i]>=0){
                int newmask=mask | 1<<i; 
                if(solve(newmask,left-nums[i],nums))return dp[left][mask]=true;
            }
        }




        return dp[left][mask]=false;

    }



    bool canPartitionKSubsets(vector<int>& nums, int k){
        n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        target = total/k;

        if(total%k!=0)return false;

       


        return  solve(0,target,nums);

    }
};