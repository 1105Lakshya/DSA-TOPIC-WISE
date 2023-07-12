/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/


/*

Consider an array that has nnn distinct numbers in the range [1,n][1,n][1,n]. For example: [1,2,3,4,5][1,2,3,4,5][1,2,3,4,5]. If we pick any one of these 5 numbers and count how many numbers are less than or equal to it, the answer will be equal to that number. So in [1,2,3,4,5][1,2,3,4,5][1,2,3,4,5], if you pick the number 444, there's exactly 4 numbers that are less than or equal to 444. If you pick 333, there's exactly 3 numbers that are less than or equal to 333, and so on. However, when you have duplicates in the array, this count will exceed the number at some point. For example: in [4,3,4,5,2,4,1][4,3,4,5,2,4,1][4,3,4,5,2,4,1], 333 has 3 numbers less than or equal to it. However, the duplicate number will have a count of numbers less than or equal to itself, that is greater than itself (in this example, 444, which is the duplicate, has 6 numbers that are less than or equal to it). Hence, the smallest number that satisfies this property is the duplicate number.

Consider an example: [4,6,4,2,1,4,3,5][4,6,4,2,1,4,3,5][4,6,4,2,1,4,3,5]. This has n+1n + 1n+1 elements where nnn = 777. Take each number from 111 to 777 and count how many numbers are less than or equal to it. In our example, count(1,2,3,4,5,6,7)count(1,2,3,4,5,6,7)count(1,2,3,4,5,6,7) = (1,2,3,6,7,8,8)(1,2,3,6,7,8,8)(1,2,3,6,7,8,8). If we performed a linear scan, we would find that the number 444 is the first number to have its counts exceed the actual number (i.e. 6 > 4) - hence 444 is the duplicate. A linear scan based approach would require an overall O(n2)O(n^2)O(n 
2
 ) time complexity in the worst case, since we'd need to iterate over each of the nnn numbers (requiring O(n)O(n)O(n) time), and then compare it to every element to generate a count of equal or lower numbers (requiring O(n)O(n)O(n) time as well - nested inside the other O(n)O(n)O(n) loop). Fortunately, countcountcount is monotonic (it's values are always in non-decreasing order), and hence it is an excellent candidate for binary search.

In the binary search approach, instead of doing a linear scan from 111 to nnn, we can apply a binary search with a goal of finding the smallest number that satisfies the aforementioned property. We start with a search space of [1,n][1,n][1,n] that has a midpoint midmidmid. If midmidmid satisfies the property, we narrow our search space to the left half [1,mid−1][1, mid - 1][1,mid−1] and continue searching, otherwise, we narrow our search space to the right half [mid+1,n][mid + 1, n][mid+1,n].

To observe the monotonicity of count, consider the evaluation: "For the given number, the count of numbers less than or equal to it, exceeds the number itself". Going back to our example, we had derived: count(1,2,3,4,5,6,7)count(1,2,3,4,5,6,7)count(1,2,3,4,5,6,7) = (1,2,3,6,7,8,8)(1,2,3,6,7,8,8)(1,2,3,6,7,8,8). If we now take the first number and apply said evaluation, we get falsefalsefalse (since count(1)==1count(1) == 1count(1)==1, which is not greater than 1). Applying this evaluation to all counts, we get (false,false,false,true,true,true,true)(false, false, false, true, true, true, true)(false,false,false,true,true,true,true). Observe how this remains falsefalsefalse in the beginning, and switches to truetruetrue for the number 4 (i.e. the duplicate), after which point it remains truetruetrue for all further numbers. Formally, the count for each number must include itself plus the count of all numbers less than itself. Since a number cannot have a negative count, each number, N, must have a count greater than or equal to the count of N-1. Since count(N)>=count(N−1)count(N) >= count(N-1)count(N)>=count(N−1), countcountcount must be monotonically increasing.

Algorithm

To recap, we need to find the smallest number such that the count of numbers less than or equal to it is greater than the number itself.

Apply binary search and start with the entire range of numbers [1,n][1,n][1,n].

Note: Binary search will be applied to the numbers in the range [1,n] (inclusive) regardless of the contents of the array. So even if a number does not exist in the array, we will still evaluate it. For example, if the array is [1,2,4,2,2,5][1,2,4,2,2,5][1,2,4,2,2,5], the algorithm will first evaluate the number 3 even though that number does not exist in the array.
Find the mid-point (curcurcur).

For curcurcur, count how many numbers in the input array are less than or equal to it.

If that number strictly exceeds curcurcur, then store that as the answer and continue to look for a smaller number that satisfies the condition by narrowing the window to the left [low,cur−1][low, cur - 1][low,cur−1].
Otherwise, narrow down the window to the right [cur+1,high][cur + 1, high][cur+1,high].
Repeat step 3 until we've exhausted the search range (i.e. until lowlowlow > highhighhigh) and return the lowest value that met the aforementioned condition.





*/









#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int i=0, j=nums.size()-1;
		while(i<=j){
			int mid=i+(j-i)/2;
			int ans=0;
			for(auto it: nums){
				if(it<=mid){ans++;}
			}
			if(ans>mid){j=mid-1;}
			else{i=mid+1;}
		}
		return i;
	}
};




class Solution {
    public:
    
    int findDuplicate(vector<int>& nums) {

        // Lambda function to count how many numbers are less than or equal to 'cur'
        auto small_or_equal = [&](int cur) {
            int count = 0;
            for (auto &num: nums) {
                if (num <= cur)
                    count++;
            }
            return count;
        };
        
        // 'low' and 'high' represent the range of values of the target
        int low = 1, high = nums.size();
        int duplicate = -1;
        while (low <= high) {
            int cur = (low + high) / 2;
            
            if (small_or_equal(cur) > cur) { 
                duplicate = cur;
                high = cur - 1;
            } else {
                low = cur + 1;
            }
        }

        return duplicate;
    }
};









int main(){
    
    return 0;
}