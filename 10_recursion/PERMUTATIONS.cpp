#include<iostream>
#include<vector>
using namespace std;

//for                        abcd   
//abcd                bacd                      cbad                  dbca
//a shuruatt mei     b in first position   c in first position       d in first position 
//                   bakkii recursion sambhal legaaaa
class Solution {
public:
void    solve(vector<int> nums ,int index,vector<vector<int>>& ans){
    //base case
        if(index>=nums.size()){
         ans.push_back(nums);
            return;
        }
        int n=nums.size();
        for(int i=index;i<n;i++){
            swap(nums[index],nums[i]);
            solve(nums,index+1,ans);
            swap(nums[index],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
        int index =0;
        solve(nums,index,ans);
        return ans;
    }
};
int main(){
    
    return 0;
}