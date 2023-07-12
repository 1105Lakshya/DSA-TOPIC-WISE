/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include<bits/stdc++.h>
using namespace std;

//if a number is excluded once it should not be included any furthur in a particular call
class Solution {
    vector<vector<int>> ans;
    vector<int> output;
    int n;

    void solve(int index,vector<int> &nums){
        if(index==n){
            ans.push_back(output);
            return ;
        }       
        
        //include
            output.push_back(nums[index]);
            solve(index+1,nums);
            output.pop_back();

        //exclude
        while(index+1< n && nums[index]==nums[index+1] ){   //if a number is excluded once it should not be included any furthur
            index++;
        }
        solve(index+1,nums);

        

    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        solve(0,nums);



        return ans;
        
        


    }
};

int main(){
    
    return 0;
}