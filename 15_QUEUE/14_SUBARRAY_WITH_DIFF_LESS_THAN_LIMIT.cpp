/*
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= limit <= 109

*/



//iss question mei humne  kya kiaa  ki hum agge bhadte rahhee or humne min or max element ka dhyan rakhha ki current subarray mei min or max element kya chal ra haiiii par agar agar unka difference meri limit ko exceed kartaa hai iska matlab jo ab naya element ayya hai meri subarray mei wo ya toh mere current minimum se bhi minimum hai ya mere current maximum se bhi maximum haii toh ab mujhe apne start pointer bhadana padega agge uske liye mujhe mere agge jo minimum and maximum exist karte hai unka pata rehna chiiye isliye mai dono ke liye ek dequeue maintain karunga jo track rakhega mera agar current minimum element agar pop hota hai toh uske pashchat meri subarray mei next minimum element konsa hai or mai fir start ko ek agge bhada ta rahunga jab tak aisa na ajjayee ki mera jo elemnt dikkat kar ra tha wo pop ho jayye maine ek agge bhadaya na ki direct deque mei jo next element hai minimum uspe challa gayya kyukii ye test case dekh 97 36 32 15 80 9  limit=87  ismei 97 or 9 jab ayyega tab 97 pop hoga or uske baad next greater 80 hai per agar hum seedha 80 par chalee gayye toh 36 32 or 15 count nahi honnggee isliye start ko ek se increment karna avashyak haii

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        if(n==1)return 1;

        deque<int> min_q;
        deque<int> max_q;
        min_q.push_front(0);
        max_q.push_front(0);

        int ans=0;

        int s=0 , e=1;
        while(e<n){
            while(!min_q.empty() && nums[e]<=nums[min_q.back()]){
                min_q.pop_back();
            }
            while(!max_q.empty() && nums[e]>=nums[max_q.back()]){
                max_q.pop_back();
            }
            cout<<s<<endl;

            min_q.push_back(e);
            max_q.push_back(e);
            if(nums[max_q.front()]-nums[min_q.front()]>limit){
                s++;
                if(s>min_q.front())min_q.pop_front();
                if(s>max_q.front())max_q.pop_front();

            }
            else{
                ans=max(ans,e-s+1);
                e++;
            }
        }

        return ans;
        
    }
};



int main(){
    
    return 0;
}