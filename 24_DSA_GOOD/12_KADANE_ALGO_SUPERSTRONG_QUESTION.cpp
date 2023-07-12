/*

1186. Maximum Subarray Sum with One Deletion



Medium
1.6K
53
Companies
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

 

Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
Example 2:

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.
Example 3:

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
 

Constraints:

1 <= arr.length <= 105
-104 <= arr[i] <= 104


*/


#include<bits/stdc++.h>
using namespace std;



    //calculated forward summaxsuarry
    //calculated backward\ summaxsubarryy
    //now considering deleting each element
    //which is negative so for that we will do maxsubarray sum to its left and maxsubarray sum to its right and the their sum
    //return max of for all n 



class Solution 
{
public:
    int maximumSum(vector<int>& v) 
    {
        int res = 0, n = v.size();
        int cur_max = v[0], overall_max = v[0];
        vector<int> forward(n);
        vector<int> backward(n);
        forward[0] = v[0];
        
        for(int i = 1; i < n; i++)
        {
            cur_max = max(v[i], cur_max + v[i]); 
            overall_max = max(overall_max, cur_max); 
  
            forward[i] = cur_max; 
        }
        
        cur_max = overall_max = backward[n - 1] = v[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            cur_max = max(v[i], cur_max + v[i]); 
            overall_max = max(overall_max, cur_max); 

            backward[i] = cur_max; 
        }
        
        res = overall_max;
        for(int i = 1; i < n - 1; i++)
        {
            res = max(res, forward[i - 1] + backward[i + 1]);
        }
        return res;
    }
};

//easy understand solution
int maximumSum(vector<int>& arr) {
        /**
         * sumEndsHere[i] : The max sum of the subarray ends at arr[i]
         * sumStartHere[i]: The max sum of the subarray starts at arr[i]
         * There two situation which can obtain the maximum subarray sum
         *  1. Get max sum without deleting any element.
         *  2. Get max sum by deleting one element. If we delete arr[i], then the 
         *     max sum of subarray is 
         *          sumEndsHere[i-1] + sumStartHere[i+1]
         *            (left to i)        (right to i)
         */
        // Time complexity : O(n)
        // Space complexity: O(n)
        vector<int> sumEndsHere(arr.size()), sumStartHere(arr.size());
        int ans = INT_MIN, size = arr.size();
        for(int i = 0, curSumF = 0, curSumB = 0; i<size; i++) {
            curSumF += arr[i];
            curSumB += arr[size-1-i];
            ans = max(ans, max(curSumF, curSumB));
            sumEndsHere[i] = curSumF;
            sumStartHere[size-1-i] = curSumB;
            curSumF = max(curSumF, 0);
            curSumB = max(curSumB, 0);
        }
        for(int i = 1; i<size-1; i++){
            ans = max(ans, sumEndsHere[i-1]+sumStartHere[i+1]);
        }
        return ans;
    }












int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}