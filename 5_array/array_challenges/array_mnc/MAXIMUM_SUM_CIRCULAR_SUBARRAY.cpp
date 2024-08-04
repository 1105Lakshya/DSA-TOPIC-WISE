/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104


*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int kadane_sum_max=0;
        int kadane_curr_sum_max=0;

        int kadane_sum_min=0;
        int kadane_curr_sum_min=0;

        int total_sum=0;
        int maxi=INT_MIN;

        for(int i=0 ;i< n;i++){
            maxi=max(maxi,nums[i]);
            total_sum+=nums[i];

            kadane_curr_sum_max+=nums[i];
            if(kadane_curr_sum_max < 0){
               kadane_curr_sum_max=0; 
            }

            kadane_sum_max=max(kadane_sum_max,kadane_curr_sum_max);



            kadane_curr_sum_min+=nums[i];
            if(kadane_curr_sum_min > 0){
                kadane_curr_sum_min=0;
            }

            kadane_sum_min=min(kadane_sum_min,kadane_curr_sum_min);


        }



    int ans=max(kadane_sum_max,total_sum-kadane_sum_min);

    if(ans<=0){
       return maxi;
    }


return ans;
    }
};





int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}