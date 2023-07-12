/*


You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
Accepted
780.3K
Submissions
1.7M
Acceptance Rate
46.2%

*/


#include<bits/stdc++.h>
using namespace std;


//MAIN LOGIC BEHIND THIS QUESTION IS THAT WE DONT CARE ABOUT THE NUMBERS LESS THAN OUR CURRENT MAXIMUM ON ITS LEFT PART BECOZ THEY WILL BE REMOVED BEFORE OUR CURRENT MAXIMUM SO NO NEED TO STORE THEM JUST USE THIS CONDITION AND WRITE CODE ACCORDINGLY

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q;//dequeue to store index of maximum if maximum gets removed due to sliding then second maximum
        vector<int> ans(n-k+1);
        q.push_back(0);
        int i=0;
        int j=1;
        while(j<k){
            while(!q.empty() && nums[q.back()] <= nums[j]  ){
                q.pop_back();
            }
            q.push_back(j++);
        }
        
        ans[i]=nums[q.front()];
        while(j<n){
            if(q.front()==i++){
                q.pop_front();;
            }
            
            while(!q.empty() && nums[q.back()] <= nums[j]){
                q.pop_back();
            }
            q.push_back(j++);

            ans[i]=nums[q.front()];


        }

    return ans;    
    }
};





int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}