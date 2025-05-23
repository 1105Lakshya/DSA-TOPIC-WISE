#include<bits/stdc++.h>
using namespace std;

class disjointSet{
public: 
    vector<int> rank, parent,size;
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0 ;i<=n ;i++){
            parent[i]=i;
            size[i]=1;
        }
    }


    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);

    }


    void unionByRank(int u ,int v){
        int ulp_u =findParent(u);  //ultimate parent of u
        int ulp_v =findParent(v);   // ultimate parent of v

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

    void unionBySize(int u,int v){
        int ulp_u =findParent(u);  //ultimate parent of u
        int ulp_v =findParent(v);   // ultimate parent of v

        if(ulp_u == ulp_v) return;

        if(size[ulp_u]< size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};





int main(){
    
    return 0;
}