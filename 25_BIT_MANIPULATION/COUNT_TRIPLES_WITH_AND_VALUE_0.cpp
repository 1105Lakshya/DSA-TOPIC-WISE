/**
 class Solution {
public:
    int countTriplets(vector<int>& nums) {

        //map to store and values of all pairs
        unordered_map<int,int> mp;


// because max value can be 64000 so we made a map as 64000 * 1000 will be our worst complexity
//if we had not made  a map then our complexity would be 1000000000 this much which would not be passed
        for(auto num1:nums){
            for(auto num2:nums){
                mp[num1&num2]++;
            }
        }

        cout<<mp[0]<<endl;

        int ans=0;
        for(auto num3:nums){
            for(auto andval:mp){
                if((num3 & andval.first)==0)ans+=andval.second;
            }
        }   

        return ans;


    }
};
*/


#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int countTriplets(vector<int>& nums) {

        //map to store and values of all pairs
        unordered_map<int,int> mp;


// because max value can be 64000 so we made a map as 64000 * 1000 will be our worst complexity
//if we had not made  a map then our complexity would be 1000000000 this much which would not be passed
        for(auto num1:nums){
            for(auto num2:nums){
                mp[num1&num2]++;
            }
        }

        cout<<mp[0]<<endl;

        int ans=0;
        for(auto num3:nums){
            for(auto andval:mp){
                if((num3 & andval.first)==0)ans+=andval.second;
            }
        }   

        return ans;


    }
};



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}