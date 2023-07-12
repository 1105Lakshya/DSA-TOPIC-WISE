/**
 You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

 

Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
Example 3:

Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
 */


#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

//JUST LIKE COIN PILES(SEARCH ON GFG) PROBLEM WE HAVE TO CONSIDER EVERY ELEMENT AS MINIMUM AND FIND ANSWER ACCORDINGLY

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;

        sort(nums.begin(),nums.end());
        arr.push_back(nums[0]);


        //made an arrya of unique elements bcoz jo equal elements hai wo toh change honge hi
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                // cout<<nums[i]<<" ,";
                arr.push_back(nums[i]);
            }
        }

        int ans=n-1;
        int len=arr.size();
        for(int i=0;i<len;i++){
            //found the elements that we have in our array if we keep curr index as mini 
            int index =upper_bound(arr.begin()+i,arr.end(),(arr[i]+n-1))-arr.begin();
         

            int include=index-i;
            

            // cout<<i<<","<<index<<","<<include<<endl;

            //updated ans
            ans=min(ans,n-include);

        }

        return ans;
    }
};