#include<bits/stdc++.h>
using namespace std;






class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        if(n1==0){
            return n2&1?nums2[n2/2]:(nums2[n2/2]+nums2[n2/2-1])/2.0;
        }
        if(n2==0){
            return n1&1?nums1[n1/2]:(nums1[n1/2]+nums1[n1/2-1])/2.0;
        }

        if(n1>n2)return findMedianSortedArrays(nums2, nums1) ;


        int l=0;
        int r=n1;
        int total=(n1+n2+1)/2;


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
                if((n1+n2)%2==1){
                    return double(max(l1,l2));
                }
                else{
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }

        }
        return 0;
    }
};





int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}