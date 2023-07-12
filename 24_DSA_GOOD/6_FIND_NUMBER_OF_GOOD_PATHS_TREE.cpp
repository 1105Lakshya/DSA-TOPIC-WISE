

/*
LeetCode Logo
Problem List
Premium
22

avatar
2421. Number of Good Paths
Hard
1.7K
90
Companies
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

 

Example 1:


Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].
Example 2:


Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
Output: 7
Explanation: There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -> 1 and 2 -> 3.
Example 3:


Input: vals = [1], edges = []
Output: 1
Explanation: The tree consists of only one node, so there is one good path.
 

Constraints:

n == vals.length
1 <= n <= 3 * 104
0 <= vals[i] <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.
*/



//toh question kehta hai dost ki tum na mujhe aise path return karo jinke bich mei us se minimum atte hai toh mai kya karunga dost mai na maximum wallleee jitte bhii haii unsabko uthhalunggaa ab maximum walla jo bhi graph mei hai unke bich mei toh unse sab choote hi hongge na toh jitte ab wo ayye unme nC2 laga dunga utne number of good paths or fir in jo maximum walle hai unko remove kardunga or graph components mei break ho jayegga ab bakki components ke liye phir se aisa hi karungaa ab agar max jo hai wo alag component mei present hai iska matlab uske bich mei unse koi greater rahha hoggaaa toh yye toh hua logic lekin sari baat yaha par bhi khatam ni hotiii is hum implement ni kar saktee bhot complexity aa jayegii isliye hum end se shuru kar re haii hum fiilhhal make chalre hai ki sarre tute hue hai fir minimumb uthha re hai or unka component banare haii firse minimum utha re hai or jo alredy banchuke hai matlab current walle se minimum unko components mei samahitt krlete haiiiii


#include<bits/stdc++.h>
using namespace std;




class Solution {

    int findParent(int a  , vector<int> &parent){
        if(parent[a]==a)return a;

        return parent[a]=findParent(parent[a],parent);
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        int ans=0;
        vector<vector<int>> adj(n);

        vector<int> parents(n,-1);




        int len=edges.size();

        for(int i=0 ;i<len;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> vis(n,false);


        //creating hashmap to get minimum  and marking everyone parents as them
        map<int,list<int>> getmin;

        for(int i=0 ;i< n;i++){
            getmin[vals[i]].push_back(i);
            parents[i]=i;
        }


        for(auto i: getmin){
            for(auto j: i.second){
                vis[j]=true;

                for(auto k: adj[j]){
                    if(vis[k]){
                        int parent1=findParent(j,parents);
                        int parent2=findParent(k,parents);
                        if(parent1!=parent2){
                            parents[parent1]=parent2;
                        }
                    }
                }
            }
            unordered_map<int,int> mp;

            for(auto j:i.second){
                mp[findParent(j,parents)]++;
            }


            for(auto t: mp){
                if(t.second>=2){
                    ans+=(t.second*(t.second-1))/2;
                }
            }
        }

ans+=n;
return ans;

    }
};



int main(){
    
    return 0;
}