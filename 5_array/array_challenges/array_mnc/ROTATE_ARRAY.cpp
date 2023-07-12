                                        // space complexity is O(n)

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//     vector<int> temp(nums.size());
//         for(int i=0;i<nums.size();i++){
//             temp[(i+k)%nums.size()]=nums[i];
//         }
// //         copy temp into an other vector
//         // swap(nums,temp);
//         nums=temp;
//     }
// };


// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]


// *********************************************VERY IMPORTANT METHOD*******************************************
// #3. Reverse the first n - k elements, the last k elements, and then all the n elements.
// Time complexity: O(n).                                                                                  Space complexity: O(1).

    // class Solution 
    // {
    // public:
        // void rotate(int nums[], int n, int k) 
        // {
            // k = k%n;        //if k greater than n this is done for that condition
    
            // Reverse the first n - k numbers.
            // Index i (0 <= i < n - k) becomes n - k - i.
            // reverse(nums, nums + n - k);
            
            // Reverse tha last k numbers.
            // Index n - k + i (0 <= i < k) becomes n - i.
            // reverse(nums + n - k, nums + n);
            
            // Reverse all the numbers.
            // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
            // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
            // reverse(nums, nums + n);
        // }
    // };
