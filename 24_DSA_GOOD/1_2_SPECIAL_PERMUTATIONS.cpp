/*


You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:

For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [2,3,6]
Output: 2
Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
Example 2:

Input: nums = [1,4,3]
Output: 2
Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums.
 

Constraints:

2 <= nums.length <= 14
1 <= nums[i] <= 109




*/



/*

Intuition
Permutations and constraints below 20??? that's bitmasking DP.

The idea is not to generate all the permutations but only those permutations which satisfy nums[i] % nums[i - 1] == 0 || nums[i - 1] % nums[i] == 0.

To create a permutation we cannot use those indices which are used before so we store visited array or bitmask (11001) where ith bit represents that ith index is visited or not.

To generate a valid permutation P from nums = [3,7,9,14,2]. we start from 0th index of P, it can have all elements from nums i.e P can start with 3, 6, 9, 12 and 15.

If P stars with 3, we mark 3 as visited mask = (10000).
For 1st index we need to insert only those numbers which are not visited (0 bit) and satisfies the condition of nums[i] % nums[i - 1] == 0 || nums[i - 1] % nums[i] == 0
But wait what is nums[i-1]?? it can be any element from index so we store a prev variable indicating the (i-1)th index.
So here we find that only 9 satisfies the condition sso we make P = [3,9] and mask is now 10100.
WHY DP?? WHERE ARE SUB-PROBLEMS?

Assume an array `nums = [3,6,9,12,15]`
we are at index 3 and `P = [3,6,9]` so `prev = 2` and `mask = 11100`
so after this 2 P's can be formed `([3,6,9,12,15], [3,6,9,15,12])`

now we are at index 3 again and  `P = [6,3,9]` so `prev = 2` and
`mask = 11100` again the answer would be 2.

This is because the current element depends on the the previous
element and the elements which were visited before it.
Approach
As we need an index i-1 to choose ith index we start by fixing the 0th index of the permutation at first.







*/


#include<bits/stdc++.h>
using namespace std;






class Solution {
public:
    vector<vector<int>> dp;


    //currentIndex is the number of set bits so no need dp for that it will be automatically handeled
    int solve(vector<int>& nums, int prevIndex, int currentIndex, int mask) {
        if (currentIndex == nums.size()) {
            return 1;
        }
        if (dp[prevIndex + 1][mask] != -1) {
            return dp[prevIndex + 1][mask];
        }
        int tot = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (mask & (1 << j)) {
                continue;
            }
            if (prevIndex == -1 || nums[prevIndex] % nums[j] == 0 || nums[j] % nums[prevIndex] == 0) {
                tot += solve(nums, j, currentIndex + 1, mask | (1 << j));
                tot %= 1000000007;
            }
        }
        dp[prevIndex + 1][mask] = tot;
        return dp[prevIndex + 1][mask];
    }

    int specialPerm(vector<int>& nums) {
        dp.resize(15,vector<int>((1 << 15) , -1));
        return solve(nums, -1, 0, 0);

    }
};

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}