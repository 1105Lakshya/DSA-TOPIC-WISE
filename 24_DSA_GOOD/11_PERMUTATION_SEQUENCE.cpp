/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!
Accepted
329.7K
Submissions
738.2K
Acceptance Rate
44.7%
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<int> factdp;
    int fact(int num){
        if(num==1)return 1;

        if(factdp[num]!=-1)return factdp[num];
        int ans=num--;
        while(num>1){
            ans*=num--;
        }
        return factdp[num]=ans;
    }


public:
    string getPermutation(int n, int k) {

        factdp.resize(10,-1);
        
        vector<int> ans;
        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }

//main kamm yaha hora haii maine k mei se subtract kiaa kia agge ki agar mera number current hai toh mai agge jitte bhi prakar se number ban re hai unko subtract karduu

        for(int i=0;i<n-1;i++){
            int j=i;
            while((k-fact(n-i-1))>0){  //subtracting agge ki arrangements 
                k-=fact(n-i-1);
                j++;  //incremented j jitni arrangements 
            }
            swap(ans[i],ans[j]); //this will come in fromt 
            sort(ans.begin()+i+1,ans.end()); //for next iteration sort it

        }


    string uttar="";
    for(int i=0;i<n;i++){
        uttar+=ans[i]+'0';
    }

    return uttar;
    }
};