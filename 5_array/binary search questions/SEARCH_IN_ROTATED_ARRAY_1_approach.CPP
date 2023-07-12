#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& arr, int s,int e, int key)
{
//     int left = 0;
//     int right = n - 1;
    while (s <= e)
    {
        int mid = s+(e-s) / 2;
        if (key == arr[mid])
            return mid;
        if (key < arr[mid])
           e = mid - 1;

        if (key > arr[mid])
            s = mid + 1;
    }

    return -1;
}
	



int getPivot(vector<int>& arr,int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
return s;
	}
int findPosition(vector<int>& arr, int n, int k)
{
int pivot=getPivot(arr,n);
// 	binary search on first line 
	if(k>=arr[pivot] && k<=arr[n-1]){
		 return binarySearch(arr,pivot,n-1,k);
	}
// 	binary search on second line 
	else{
		return binarySearch(arr,0,pivot-1,k);
	}
}

int main(){
    
    return 0;
}