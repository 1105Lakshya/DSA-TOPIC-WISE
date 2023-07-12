
//QUESTION
/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers. 


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= N <= 105
0 <= a[i] <= 105
*/

//SOLUTIONNN

// approach

/*
we will make a set and put all the values of the array inside thhe set and then we will check for every element if a nummber one lesser than it exists or not 
if it exists then we will do nothing and skip it else we find from that element its chain 
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(int i=0 ;i<n;i++){
            st.insert(nums[i]);
        }
        int ans=0;
    for(auto i:st){

        if(st.find(i-1)==st.end()){
            int tempans=1;
            while(st.find(i+1)!=st.end()){
                tempans++;
                st.erase(i+1);
                i++;
            }
            ans=max(tempans,ans);
        }
    }
        
        return ans;
    }
};


int main(){
    
    return 0;
}