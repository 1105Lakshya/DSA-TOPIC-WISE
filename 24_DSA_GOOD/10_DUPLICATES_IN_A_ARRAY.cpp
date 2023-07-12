/*

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.

*/


//WATCH NISHANT CHAHAR VIEDO TO UNDERSTAND ONLI 7minutes VIDEO


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();

        if(n==1)return {};




        for(int i=0;i<n;i++){
            int index=(--nums[i])%n;
            nums[index]+=n;  //adding n so that we can get our number by doing mod 
            //keeping the count by incrementing times n 
            //linear solution and no space used
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if((nums[i]/n)> 1){
                ans.push_back((i+1));
            }
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