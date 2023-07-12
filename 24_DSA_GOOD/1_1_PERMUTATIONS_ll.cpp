/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10

*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
    void solve(vector<int> output,int index, vector<vector<int>>&ans){
        int n=output.size();
        if(index==n-1){
            ans.push_back(output);
            return ;
        }
        //set track rakheega kon kon pehlii position pe aa chuukka haiiii
        unordered_set<int> st;
        //pehla toh process krna hi haiii 
        solve(output,index+1,ans);
        
        st.insert(output[index]);
        
        //bakkki jo pehlii position pe nahii ayye unko process
        for(int i=index+1 ;i<n;i++){   
            if(st.find(output[i])==st.end()){
            swap(output[index],output[i]);
            st.insert(output[index]);
            solve(output,index+1,ans);
            }
        }
        return ;
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0 ,ans);
        return ans;
    }
};




int main(){
    
    return 0;
}