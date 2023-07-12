/*

2305. Fair Distribution of Cookies
Medium
1.5K
66
Companies
You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

Return the minimum unfairness of all distributions.

 

Example 1:

Input: cookies = [8,15,10,20,8], k = 2
Output: 31
Explanation: One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
Example 2:

Input: cookies = [6,1,3,2,2,4,1,2], k = 3
Output: 7
Explanation: One optimal distribution is [6,1], [3,2,2], and [4,1,2]
- The 1st child receives [6,1] which has a total of 6 + 1 = 7 cookies.
- The 2nd child receives [3,2,2] which has a total of 3 + 2 + 2 = 7 cookies.
- The 3rd child receives [4,1,2] which has a total of 4 + 1 + 2 = 7 cookies.
The unfairness of the distribution is max(7,7,7) = 7.
It can be shown that there is no distribution with an unfairness less than 7.
 

Constraints:

2 <= cookies.length <= 8
1 <= cookies[i] <= 105
2 <= k <= cookies.length




*/



#include<bits/stdc++.h>
using namespace std;


class Solution_BACKTRACKING {
    vector<int> arr;
    int ans;
    int k;
    int n;

    void solve(int index,int &maxi,vector<int> &cookies){
        if(index==n){
            ans=min(ans,maxi);
        }

        cout<<index<<endl;

        if(ans<=maxi)return ;


        unordered_set<int> st;


        for(int i=0;i<k;i++){
            if(st.find(arr[i])==st.end()){
                st.insert(arr[i]);
                arr[i]+=cookies[index];
                if(maxi<arr[i]){
                    int temp=maxi;
                    maxi=arr[i];
                    solve(index+1,maxi,cookies);
                    maxi=temp;
                    arr[i]-=cookies[index];
                }
                else{
                    solve(index+1,maxi,cookies);
                    arr[i]-=cookies[index];
                }
            }
        }




    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        arr.resize(k,0);
        n=cookies.size();


        ans=INT_MAX;
        int maxi=INT_MIN;
        this->k=k;

        solve(0,maxi,cookies);


        return ans;


    }
};



class Solution_BITMASK { 
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<vector<int>>dp(k + 1, vector<int>(1ll << n, INT_MAX));
        
        vector<int>sum(1ll << n);
        for(int mask = 0;mask<(1ll << n); mask++){
            int total = 0;
            for(int i = 0;i<n;i++){
                if(mask & (1ll << i)){
                    total += cookies[i];
                }
            }
            sum[mask] = total;
        }

        dp[0][0] = 0;
        for(int person = 1;person<=k;person++){
            for(int mask = 0;mask<(1ll << n);mask++){
                //ENUMERATING ALL SUBMASKS OF A MASK
                for(int submask=mask;submask;submask=(submask - 1)&mask){
                    dp[person][mask] = min(dp[person][mask], max(sum[submask], dp[person - 1][mask ^ submask]));
                }
            }
        }

        return dp[k][(1ll << n) - 1];
    }   
};




















int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}