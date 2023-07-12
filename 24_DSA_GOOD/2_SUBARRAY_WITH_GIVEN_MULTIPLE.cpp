/*
523. Continuous Subarray Sum
Medium

3069

339

Add to List

Share
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= sum(nums[i]) <= 231 - 1
1 <= k <= 231 - 1
*/


//prefix sum array bannallii or fir traverse krte rahhe or check kiyya kya humare jo remainder arra hai wo pehlee bhii ayaa hua haii if yes then check ki humari subarray ka size greater than two hooo 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        unordered_map<int,int> mp;
        mp[0]=-1;
        mp.insert({arr[0]%k,0});
        for(int i=1;i<n;i++){
            int num=arr[i]%k;
            auto it=mp.find(num);
                if(it!=mp.end() && (i-it->second)>1){
                    return true;
                }
            mp.insert({num,i});
        }
        
        return false;
    }
};



int main(){
    
    return 0;
}