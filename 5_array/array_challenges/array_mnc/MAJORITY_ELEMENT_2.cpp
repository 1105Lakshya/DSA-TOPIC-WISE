/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
*/



/*
The first idea that comes to mind is to use a hash map to store the count of each number in the array. However, the problem constraints state that we need to solve the problem in O(1) space complexity.

We can use the Boyer-Moore Voting Algorithm to solve this problem in linear time and O(1) space complexity. The algorithm is as follows:

Initialize two variables, num1 and num2, to None and two variables, count1 and count2, to 0.
Iterate through the array and perform the following steps for each element:
a. If the element is equal to num1, increment count1 by 1.
b. Else if the element is equal to num2, increment count2 by 1.
c. Else if count1 is 0, set num1 to the element and count1 to 1.
d. Else if count2 is 0, set num2 to the element and count2 to 1.
e. Else decrement count1 and count2 by 1.
Reset count1 and count2 to 0 and iterate through the array again to count the occurrences of num1 and num2.
If the count of num1 is greater than n/3, add it to the result list.
If the count of num2 is greater than n/3 and num2 is not equal to num1, add it to the result list.
Return the result list.
The time complexity of this algorithm is O(n) and the space complexity is O(1).


*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int num1=0;
        int num2=0;

        int count1=0;
        int count2=0;

        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=num2){
                num1=nums[i];
                count1=1;
                continue;
            }
            if(count2==0 && nums[i]!=num1){
                num2=nums[i];
                count2=1;
                continue;
            }

            if(num1==nums[i]){
                count1++;
            }
            else if(num2==nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }



        int target=n/3; 
        count1=0;
        count2=0;
        for(int i=0;i<n;i++){
            if(num1==nums[i])count1++;
        }

        if(num1!=num2){
        for(int i=0;i<n;i++){
            if(num2==nums[i])count2++;
        }    
        }
        vector<int> ans;
        
        if(count1>target)ans.push_back(num1);
        if(count2>target)ans.push_back(num2);



        return ans;
        
    }
};

int main(){
    
    return 0;
}