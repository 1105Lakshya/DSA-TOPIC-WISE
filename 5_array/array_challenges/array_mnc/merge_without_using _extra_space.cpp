// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	int i=0;
	while(i<n){
	    if(arr1[i]>arr2[0]){
	        swap(arr1[i],arr2[0]);
	  i++;
        for(int j=0;j<m-1;j++){
	  if(arr2[j+1]<arr2[j]){
               swap(arr2[j+1],arr2[j]);
           } 
           else{
               break;
           }           
        }
	    }
	    else{
	        i++;
	    }
	    
	}
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends