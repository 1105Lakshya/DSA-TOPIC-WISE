/*

Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 


*/


//           USING 2N SPACE  NOT OPTIMALL      
/*
class Solution{

    // Function to find the trapped water between the blocks.
    private:
    void leftArray(int arr[], int n, vector<int> & left){
        left[0]=arr[0];
        for(int i=1;i< n;i++){
            left[i]=max(arr[i],left[i-1]);
        }
    }
    void rightArray(int arr[], int n, vector<int> & right){
        right[n-1]=arr[n-1];
        for(int i=n-2;i>= 0;i--){
            right[i]=max(arr[i],right[i+1]);
        }
    }
    public:
    long long trappingWater(int arr[], int n){
        vector<int> leftGreatest(n);
        vector<int> rightGreatest(n);
        leftArray(arr, n , leftGreatest);
        rightArray(arr, n , rightGreatest);
        // for(int i=0;i< n;i++ ){
        //     cout<<"deepika "<<leftGreatest[i]<<endl;
        // }
        // cout<<"lakshya "<<endl;
        // for(int i=0;i< n;i++ ){
        //     cout<<"deepika "<<rightGreatest[i]<<endl;
        // }
        long long int water=0;
        for(int i=0;i< n;i++){
            water+=min(leftGreatest[i],rightGreatest[i])-arr[i];
        }
        return water;
    }};

*/




//TWO POINTER SOLUTION 
/*




*/