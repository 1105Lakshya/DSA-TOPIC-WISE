//****************************** TIME COMPLEXCITY OF THIS ALGORITHIM IS LOG(N) *******************************************                                        
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (key == arr[mid])
            return mid;
        if (key < arr[mid])
            right = mid - 1;

        if (key > arr[mid])
            left = mid + 1;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter the length of array" << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout<<"enter the key"<<endl;
    cin>>key;
    cout<<binarySearch(arr,n,key);
    return 0;
}