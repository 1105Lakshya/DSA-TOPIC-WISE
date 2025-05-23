/*
2035. Partition Array Into Two Arrays to Minimize Sum Difference
Solved
Hard
Topics
Companies
Hint
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

 

Example 1:

example-1
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
Example 2:

Input: nums = [-36,36]
Output: 72
Explanation: One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
Example 3:

example-3
Input: nums = [2,-1,0,4,-2,-9]
Output: 0
Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
 

Constraints:

1 <= n <= 15
nums.length == 2 * n
-107 <= nums[i] <= 107
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    //watch aryan mittal video on meet in the middle technique
public:
    int minimumDifference(vector<int>& nums) {
        int N =nums.size(),res=INT_MAX,sum=0;
        sum=accumulate(nums.begin(),nums.end(),0);

        int n=N/2;
        vector<vector<int>> left(n+1),right(n+1);
        for(int mask=0;mask<(1<<n);mask++){
            int sz=0,l=0,r=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    sz++;
                    l+=nums[i];
                    r+=nums[i+n];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for(int sz=0;sz<=n;sz++){
            sort(right[sz].begin(),right[sz].end());
        }

        for(int sz=0;sz<n;sz++){
            for(auto &a:left[sz]){
                int b=(sum-2*a)/2,rsz=n-sz;
                auto &v=right[rsz];
                auto itr=lower_bound(v.begin(),v.end(),b);

                if(itr!=v.end())res=min(res,abs(sum-2*(a+(*itr))));
                if(itr!=v.begin()){
                    auto it=itr;it--;
                    res=min(res,abs(sum-2*(a+(*it))));
                }
            }
        }
        return res;
    }
};








int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}