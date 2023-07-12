/*
You are given a 0-indexed array nums comprising of n non-negative integers.

In one operation, you must:

Choose an integer i such that 1 <= i < n and nums[i] > 0.
Decrease nums[i] by 1.
Increase nums[i - 1] by 1.
Return the minimum possible value of the maximum integer of nums after performing any number of operations.

 

Example 1:

Input: nums = [3,7,1,6]
Output: 5
Explanation:
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.
Example 2:

Input: nums = [10,1]
Output: 10
Explanation:
It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.
 

Constraints:

n == nums.length
2 <= n <= 105
0 <= nums[i] <= 109
*/

#include<bits/stdc++.h>
using namespace std;


//GO ON LEETCODE SEE THE EDITORIALLL  SOLUTION AND THEN READ BELOW LINES

class Solution {

 //dekhoo bhaiii ismeiii greedy toh ye haii ki agar minimum chiiyyee toh wo pureee total ka division hi hotaa  haiii  or  kyukii humarii pichlii arrayy mei hum sirf increase kar sakte haii toh humara answer minimum nahhii maximum hogaaaa kyukii wo pichhe walii value decrease toh nahi ho saktiiii tatparyyaaaaaaaaaa uskee baadd jo bhii valueess ayiiii haiiinnnn wo sabhiii mithhyaa haiinnnnn or maximum walllaaaaaa hii humaraaaa uttar hhaiii isliyee humne prefix sum banayyyaaaaa chalo prefix toh theek haii but maximum kyu le rahe hai wo clear hona chiiyyeee OK BETA
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        long long int pre_sum=nums[0];
        int n=nums.size();
        int ans=nums[0];
        for(int i=1;i< n;i++){
            pre_sum+=nums[i];
            int new_ans=pre_sum/(i+1);  // i+1 is totall length for averagee 
            if(pre_sum%(i+1)!=0)new_ans++;

            ans=max(ans,new_ans);
        }

        return ans;
        
    }
};



int main(){
    
    return 0;
}