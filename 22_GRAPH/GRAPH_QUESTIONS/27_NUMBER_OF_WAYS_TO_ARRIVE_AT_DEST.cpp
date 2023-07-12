/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
 

Constraints:

1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.

*/


#include<bits/stdc++.h>
using namespace std;


//count array bana liyya hum kisi node pe agar minimum dist se pohoch re hai toh uske ways hum us se pichle node tak kitne mei pohoche thee wo haii or agar equal ajjaye toh hum previous walli node ko add kardengeeee



#define MOD 1000000007

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,long long int >>> adj(n);

        for(auto &road : roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }



        vector<long long int> mindist(n,1e18);
        mindist[0]=0;

        vector<long long int> paths(n,1);
        paths[0]=1;

        priority_queue<pair<long long int ,int> , vector<pair<long long int ,int>> , greater<pair<long long int,int>>> pq;

        pq.push({0,0});
        while(!pq.empty()){
            pair<long long int ,int> curr=pq.top();
            pq.pop();

            int node=curr.second;
            long long int nodedist=curr.first;

            if(nodedist>mindist[node])continue;

            for(auto neigh:adj[node]){
                long long int totaldist=nodedist+neigh.second;
                if( totaldist< mindist[neigh.first]){
                    paths[neigh.first]=paths[node];
                    mindist[neigh.first]=totaldist;

                    pq.push({mindist[neigh.first],neigh.first});
                }
                else if(totaldist==mindist[neigh.first]){
                    paths[neigh.first]%=MOD;
                    paths[neigh.first]+=paths[node] ;
                    paths[neigh.first]%=MOD;
                }


            }


        }


        return paths[n-1];

        

        
    }
};











int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}