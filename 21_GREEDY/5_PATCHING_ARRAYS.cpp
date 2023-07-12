/*
Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

Return the minimum number of patches required.

 

Example 1:

Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.
Example 2:

Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].
Example 3:

Input: nums = [1,2,2], n = 5
Output: 0
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
nums is sorted in ascending order.
1 <= n <= 231 - 1
1*/


//greedy ye hai ki pehle maine bana liya ki mai yaha tak ke sare sum nikal pa raha huu suppose mere pass ye hai ki max_genrate tak mai sare numbers nikal sakta hu ab agar mere ko max generat ko bhadana hai taki wo target tak pohoche toh mere pass do tarik hai mai ya toh array mei se uthalu number kyuki 1 to max generat mai bana sakta hu toh usmei mai fir max_generate + nums[i] tak bana paunga by adding previous max_genrte sum to the number and if I am not able to genrate the numbers uptill the number present in array then I will add the next number to it the patch 


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch=0;
        if(nums[0]!=1)patch+=1; 
        if(n==1)return patch;
        
        int length=nums.size();

        long long  max_generate=1;
        int start;
        if(patch==1)start=0;
        else start=1;
        while(max_generate<n){
            if(start<length){
            if(max_generate<nums[start]-1){
                patch+=1;
                max_generate+=max_generate+1;
            }
            else{
                max_generate+=nums[start];
                start++;
            }    
            }
            else{
                patch+=1;
                max_generate+=max_generate+1;
            }
            
        }


        return patch;
    }
};


int main(){
    
    return 0;
}