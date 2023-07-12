/*

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        vector<int > prefixsum(n+1);    //creating prefix sum array 
        prefixsum[0]=0;    
        for(int i=0;i< n;i++){
            sum+=nums[i];
            prefixsum[i+1]=sum;
        }
        int count=0;
        
        
        unordered_map<int,int>  check;
        check[0]=1;
        for(int i=1;i<n+1;i++){
            int num=prefixsum[i]-k;
            if(check.find(num)!=check.end()){    //agar prefixsum[i]-k map mei exist krtta haii toh matlab subarray with sum k present haiiii
                count+=check[num];
            }
            check[prefixsum[i]]++;
        }
        return count;
    }
};
