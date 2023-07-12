/*
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7
Explanation :
3rd smallest element in the given 
array is 7.
Example 2:

Input:
N = 5
arr[] = 7 10 4 20 15
K = 4
Output : 15
Explanation :
4th smallest element in the given 
array is 15.


*/




//ALGO
/*
ALGO SAYS WE WILL MAINTAIN A HEAP OF K ELEMENTS WHENEVER THERE WILL BE AN  ELEMENT WHOSE VALUE IS LESS THAN THE TOP(MAX VALUE AMONG)
THE K ELEMENTS THEN IT MEANS WE NEED TO INCLUDE IT IN K SMALLEST ELEMENTS SO WE WILL POP FROM HEAP AS WE WILL REMOVE THE MAXIMUM 
ELEMENT IN ORDER TO HAVE K SMALLEST ELEMENTS OF ARRAAYY IN THE END WE WILL HAVE A HEAP CONTAINING K SMALLEST ELEMENTS OF ARRAY 
AND K TH SMALLEST ELEMENT WILL BE THE TOP OF HEAPPP
*/

//SOLUTION
/*
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        
        //step1  ---->  K elements ka heap banna liyaaa
        for(int i=0 ;i<k ;i++){
            pq.push(arr[i]);
        }
        
        //step2----> popping and pushing if an element is less than heap ka top
        for(int i=k ;i<=r ;i++){
            if(arr[i]< pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        
        //step3 ----> answer will be top of heap
        return pq.top();
    }
};


*/