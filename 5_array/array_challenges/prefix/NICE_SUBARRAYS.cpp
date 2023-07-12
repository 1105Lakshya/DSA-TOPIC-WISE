/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/


#include<bits/stdc++.h>
using namespace std;







class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        vector<int> prefix(n+1,0);
        for(int i=0 ;i< n;i++){
            if(nums[i]&1){
                count++;
            }
            prefix[i+1]=count;
        }
        int i=0;
        int j=1;
        int ans=0;
        while(j<n+1){
            if(prefix[j]-prefix[i]==k){
                int count1=1;
                i++;
                while(prefix[i]==prefix[i-1]){
                    count1++;
                    i++;
                }

                j++;
                int count2=1;
                while(j<n+1 && prefix[j]==prefix[j-1]){
                    j++;
                    count2++;
                }
                ans+=count2*count1;
            }
            else if(prefix[j]-prefix[i]<k){
                j++;
            }
            else{
                i++;
            }
        }
return ans;

    }
};





int main(){
    
    return 0;
}