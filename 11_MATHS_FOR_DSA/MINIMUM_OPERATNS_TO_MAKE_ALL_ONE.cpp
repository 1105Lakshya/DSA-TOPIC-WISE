// You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:

// Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
// Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.

// The gcd of two integers is the greatest common divisor of the two integers.

 

// Example 1:

// Input: nums = [2,6,3,4]
// Output: 4
// Explanation: We can do the following operations:
// - Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
// - Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
// - Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
// - Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
// Example 2:

// Input: nums = [2,10,6,14]
// Output: -1
// Explanation: It can be shown that it is impossible to make all the elements equal to 1.
 

// Constraints:

// 2 <= nums.length <= 50
// 1 <= nums[i] <= 106
 

// Follow-up:

// The O(n) time complexity solution works, but could you find an O(1) constant time complexity solution?

// Accepted
// 9.1K
// Submissions
// 25.9K
// Acceptance Rate
// 35.2%


//to do it in linear time complexity start from index 0 and move towards end as soon as gcd becomes one start traversing in backward direction from that index and stop when the gcd while coming backwards becomes one this is your subarrayyyy then dont forget to move forward from that point since we want minimum so ho sakta hai agge chalke or choootiii subarrayyy mill jayyee jiskkkaa gcd 1 hoo.








#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // check if there is 1 in `nums`
        int ones = count(nums.begin(), nums.end(), 1);
        // if so, we can make all the other elements equal to 1 with one operation each
        // e.g. [2,6,1,4] -> [2,1,1,4] -> [1,1,1,4] -> [1,1,1,1]
        // the number of operation to make all equal to 1 is simply n - number of 1s
        if (ones) return n - ones;
        int res = INT_MAX;
        // try finding the shortest subarray with a gcd equal to 1.
        for (int i = 0; i < n; i++) {
            // subarray starting from i
            int g = nums[i];
            // try each element after i
            for (int j = i + 1; j < n; j++) {
                // to calculate gcd
                g = __gcd(g, nums[j]);
                // if the gcd is 1
                if (g == 1) {
                    // then we calculate the min ops
                    res = min(res, j - i);
                }
            }
        }
        // no result -> return -1
        if (res == INT_MAX) return -1;
        // otherwise, return res + n - 1
        // i.e. the min ops to turn the shortest subarray to 1 + 
        //      use that 1 to convert n - 1 elements to 1
        return res + n - 1;
    }
};