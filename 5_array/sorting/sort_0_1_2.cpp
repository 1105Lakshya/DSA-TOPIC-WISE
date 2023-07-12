
// C++ program to sort an array
// with 0, 1 and 2 in a single pass
#include <bits/stdc++.h>
using namespace std;

// Function to sort the input array,
// the array is assumed
// to have values in {0, 1, 2}
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
         int start=0,end=n-1;
        int i=0;   //this pointer will iiterate over the loop and will 
        while(i<=end){
            if(arr[i]==0){
                swap(arr[i],arr[start]);
                    start++;
                }
            else            
                if(arr[i]==2){
                swap(arr[i],arr[end]);
                end--;
                continue;
                 }
            i++;
            }
    return ;    
    }
};

// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}

int main(){
    int n;
    cin>> n;
    vector<int> arr(n);
    cout<< "The size of arr vector is "<< arr.size();
    for(int i=0;i< n;i++){
    int temp;
    cin>> temp;
    arr.push_back(temp);
    cout<< "The size of arr vector is "<< arr.size();
    }
    Solution brr;
    brr.sortColors(arr);
    for(auto it = arr.begin();it!=arr.end();it++){
        cout<< *it<< " ";
    }

}