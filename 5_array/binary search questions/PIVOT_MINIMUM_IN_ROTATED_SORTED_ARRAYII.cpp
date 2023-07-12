/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.
*/

//same as finding pivot in rotated sorted just the elements are not uniquueee
//they can be same 
//so since we are running our binary search on the condition that weather our mid element is greater than the last element of array or less than toh numbers same hone se dikkate ye hogi ki hum tab ni decide kar payenge jab humara last elment or mid barabar hongee 

//lets take ans exaple 
//  4 4 4 4 4 4 4 4 4 4 4 4 4 4 1 2 3  4 4 4 4 4 
// in the above case out mid elment and the last elment is same  so obserrvation is that in the right part wale bhot sare 4 we only have 4 and no other elment before the ending so this will be ours criterie to decide the space for binaryr search o k m i t r 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        int e=n-1;
        int m=(s+e)/2;
        
        while(s<e){
            if(nums[m]<nums[e]){
                e=m;
            }
            else if(nums[m]>nums[e]){
                s=m+1;
            }
            else{
                int temp=m+1;
                while(temp<e && nums[temp]==nums[temp-1]){
                   temp++; 
                }
                if(temp==e){
                    e=m;
                }
                else{
                    s=m+1;
                }
            }
            m=(s+e)/2;
        }
        return nums[s];
    }
};



int main(){
    
    return 0;
}