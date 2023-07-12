/*
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
 

Constraints:

1 <= nums.length <= 105
nums.length == n
-109 <= nums[i] <= 109
-109 <= lower <= upper <= 109
*/


// Number of pairs with sum >= lower and <= upper
// = (Number of pairs with sum <= upper) - (Number of pairs with sum < lower)

// class Solution {
//     public long countFairPairs(int[] nums, int lower, int upper) {
//         // sort the array to make your life easier
//         Arrays.sort(nums);
//         return smaller(nums, upper) - smaller(nums, lower - 1);
//         //              |                        |
//         //         pairs with               pairs with
//         //        sum <= upper              sum < lower

//         // Why lower - 1? because we want to include lower
//     }

//     private long smaller(int[] nums, int value) {
//         // initialise pointers at index 0 and last
//         int l = 0, r = nums.length - 1;
//         long result = 0;
//         while (l < r) {
//             int sum = nums[l] + nums[r];
//             // If left and right have sum smaller than target,
//             // means all elements from l+1 to r form a pair with l
//             // say we have found the subarray [2,3,4,5] and target is 7           
//             // (2,3), (2,4), (2,5) are pairs with sum <= 7
//             if (sum <= value) {
//                 // number of such pairs: 3 (2 with 3, 4, 5) 
//                 // which will be given by l - r
//                 result += (r - l);
//                 l++;    // move up to look for more pairs
//             } else {    // if sum is greater, decrement right pointer
//                 r--;
//             }
//         }
            
//         return result;
//     }
// }