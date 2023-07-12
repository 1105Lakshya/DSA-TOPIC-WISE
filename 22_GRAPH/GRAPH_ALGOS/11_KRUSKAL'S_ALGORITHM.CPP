#include<bits/stdc++.h>
using namespace std;

// QUESTION//
/*
FIND THE SUM OF WEIGHTS OF THE MINIMUM SPANNING TREE OBTAINED FROM A GRAPHH
*/


//ALGO
/*
KRUSKALS ALGO
We will have a data structure that will contain edges(two nodes and their weight) in sorted manner we will traverse and if the two nodes obtained have different 
parent then we will merge them or union them else we will ignore i.e if the nodes have same parent we will ignore

UNION FUNCTION
we will check the parent of both the nodes if the parent have same ranks then we will assign any node as a parent node to other and then we will increament
the rank of the parent node 

if one has greater rank than the other then will make the node with higher rank the parent of the node with lower rank   (NO NEED TO INCREAMENT IN THIS CASE)

FINDPARENT
jab tak node ka parent khud node na ho tab tak node =parent[node]
for reducing time complexity we will do rank compression

*/




#include<algorithm>

//  COMPARATOR REMEMBBER VERRRRRRRRRRRRRRRRRRRRRYYYYYYYYYYYYYYYYYYYYYY IMPORTANT CONCEPT
bool cmp(vector<int> &a ,vector<int> &b){
   return a[2]<b[2];
}

void makeSet(vector<int> &parent ,vector<int> &rank, int n){
//     inititalising rank and parent array 
    for(int i=0 ;i< n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int  findParent(vector<int> &parent ,int node){
    int tempNode=node;
    while(parent[tempNode]!=tempNode){
        tempNode=parent[tempNode];
    }
    parent[node]= tempNode;     //path compression for future visit
     return tempNode;
//     if(parent[node]==node){
//         return node;
//     }
//     return parent[node]=findParent(parent,parent[node]);
}


void unionSet(int u ,int v ,vector<int> &parent ,vector<int> &rank){
    int parent1=findParent(parent,u);
    int parent2 =findParent(parent,v);
    
    if(rank[parent1] < rank[parent2]){
        parent[parent1]=parent2;
    }
    else if(rank[parent2]<rank[parent1]){
        parent[parent2]=parent1;
    }
    else{
        parent[parent2]=parent1;
        rank[parent1]++;
    }
}



int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
 sort(edges.begin() ,edges.end(),cmp);
 vector<int> parent(n);
 vector<int> rank(n);
 makeSet(parent,rank,n);
    
    int totalweight =0;
    
    for(int i=0 ;i< edges.size();i++){
        int u =findParent(parent,edges[i][0]);
        int v =findParent(parent,edges[i][1]);
        int wt= edges[i][2];
        
        
        if(u!=v){
            totalweight +=wt;
            unionSet(u ,v ,parent ,rank);
        }
    }
    return totalweight;
}






int main(){
    
    return 0;
}