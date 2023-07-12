/*


*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int n;   
    unordered_set<int> factors;
    unordered_map<int,int> mp;
public:

    void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        factors.insert(2);
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            factors.insert(i);
            n = n/i;
        }
    }
 
    if (n > 2)
        factors.insert(n);
}
    
    vector<int> rank, parent;
    
    

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }


    void unionByRank(int u ,int v){
        int ulp_u =findParent(u);  
        int ulp_v =findParent(v);   

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u]< rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        if(rank[ulp_v]< rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
}
    


    bool canTraverseAllPairs(vector<int>& nums) {
        n=nums.size();
        rank.resize(n+1,0);
        parent.resize(n+1,0);

        for(int i=0 ;i<=n ;i++){
            parent[i]=i;
        }


        for(int i=0;i<n;i++){
            primeFactors(nums[i]);
            for(auto factor:factors){
                if(mp.find(factor)==mp.end()){
                    mp[factor]=i;
                }
                else{
                    unionByRank(i,mp[factor]);
                }
            }
            factors.clear();
        }

    for(int i=1;i<n;i++){
        if(findParent(i)!=parent[0]){
            return false;
        }
    }
    
    return true;

        
    
        
    }
};