//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int> nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        
        if(n1>n2)return kthElement(k,nums2,nums1);
        
        int l=max(0,k-n2); //MAIN PART OF THE QUESTION
        int r=min(k,n1);   //MAIN PART OF THE QUESTION
        int total=k;
        
        while(l<=r){
            int mid1=(l+r)/2;
            int mid2=total-mid1;

            int l1=INT_MIN;
            if(mid1-1>=0 )
            l1=nums1[mid1-1];

            int l2=INT_MIN;
            if(mid2-1>=0 )
            l2=nums2[mid2-1];


            int r1=INT_MAX;
            if(mid1<n1)
            r1=nums1[mid1];

            int r2=INT_MAX;
            if(mid2<n2 )
            r2=nums2[mid2];

            if(l1>r2){
                r=mid1-1;
            }
            else if(l2>r1){
                l=mid1+1;
            }
            else{
                return max(l1,l2);
            }
            
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends