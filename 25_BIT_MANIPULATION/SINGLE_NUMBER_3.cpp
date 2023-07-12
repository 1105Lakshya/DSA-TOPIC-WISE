/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/


#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo = 0;
        for(auto i : nums)
        xo^=i;
        int pos = 0; 
        //finding the first bit where the two numbers differ 
        while(true)
        {
            if(xo & (1 << pos)) break;
            pos++;  
        }
        xo = (1 << pos); //here we find a number who has that bit set in which the two numbers differ 

        //furthur we divide the numbers in two halfs the number having that bit set and the numbers having that bit not set now after this division xoring the individual groups will give us our answer 
        vector<int> ans(2,0);
        for(auto i : nums)
        {
            if(xo & i) ans[0]^=i;
            else ans[1]^=i;
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