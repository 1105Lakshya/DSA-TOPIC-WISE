#include<bits/stdc++.h>
using namespace std;

int main(){

    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    int mod=1e9+7;


    int n;
    int k;
    int d;
    cin>>n>>k>>d;


    int num=n/d +1;

    vector<vector<int>> dp(num+1,vector<int>(n+1,0));


    dp[num+2][0]=1;


    for(int i=num+1;i>=0;i--){
        for(int j=k;j>=d;j--){
            for(int t=0;t<=n;t++){
                if(t+j<=n){
                    dp[i][j]+=dp[i+1][t+j];
                }
            }
        }
    }


    cout<< dp[0][n];

    

return 0;

}