/*

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100


*/








/*
class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        // if(n==1){
        //     return ;
        // }
        int index1=-1;
        for(int i=n-1;i>0;i--){
            if(arr[i-1]<arr[i]){
                index1=i-1;                        // finding the index 
                break;
            }
        }
        // cout<<index1<<endl;
        if(index1==-1){
            reverse(arr.begin(),arr.end());
            return ;
        }
        for(int i=n-1;i>index1;i--){
            if(arr[i]>arr[index1]){
                swap(arr[i],arr[index1]);                    //uss index pr jo number hai us se just badaa number chaiiyee so fir se end se travel krnna shuruuu kreenge or jo bhi pehla bandda dikhha usse index walle se swap krdiyyaa
                break;
            }
        }
        auto it=arr.begin();
        sort(it+index1+1,arr.end());                           // next permutation ke liye index ke agge wallo ko sort krdiiyaaa
        return ;    
        
        
        
    }
};

*/