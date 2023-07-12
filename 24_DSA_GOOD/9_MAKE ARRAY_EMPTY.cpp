/*
You are given an integer array nums containing distinct numbers, and you can perform the following operations until the array is empty:

If the first element has the smallest value, remove it
Otherwise, put the first element at the end of the array.
Return an integer denoting the number of operations it takes to make nums empty.

 

Example 1:

Input: nums = [3,4,-1]
Output: 5
Operation	Array
1	[4, -1, 3]
2	[-1, 3, 4]
3	[3, 4]
4	[4]
5	[]
Example 2:

Input: nums = [1,2,4,3]
Output: 5
Operation	Array
1	[2, 4, 3]
2	[4, 3]
3	[3, 4]
4	[4]
5	[]
Example 3:

Input: nums = [1,2,3]
Output: 3
Operation	Array
1	[2, 3]
2	[3]
3	[]
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
All values in nums are distinct.



*/



// here the idea is  suppose question iss     4 5 1 6 2 3 8 7
// isko karenge aise ki pehle chhakar mei  1 2 3 nikal jayengee
// then                                    4 5 6 
// then                                    7
// then                                     8 



//bas phir priority queue banake solve kardiiaa mast question tha jo baat haii

#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
         int  n=nums.size();
priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        pq.push({nums[i],i});
    }
    int removed=0;
    long long int ans=0;
    while(!pq.empty()){
        ans+=n-removed;
        int prev=-1;
        while(!pq.empty() && pq.top().second>prev ){
            prev=pq.top().second;
            pq.pop();
            removed++;
        }
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