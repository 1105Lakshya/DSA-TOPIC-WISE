/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
*/

#include<bits/stdc++.h>
using namespace std;


//here dijkstara algo will fail as wo kisi bhi node tak bas minimum distance pe pahucha degii agar hum number of nodes ka check bhii laga dee then also it will use all the permitted stops in the starting to reach a particular node however it may be possible that you have to reach a certain node with a greater distance and use the remaining  stops for further traversal in order to have shortest distance 



// so here maine kya kiyaa dost ki bfs traversal marr diaa matlab ek stop ka agar mai use karuu toh kaha kaha pahuch rahha hunn phir do stop mei kaha kaha pahuch raha hun
// or agar do stop ka use karkkee kahi minimum distance milra hai uss  node ka jo alredy visited ho chukii haiii toh mai q mei ussee bhii push kardunga agar distance gretare hai toh push karne ka koi fayeda ni hai kyuki us se pehle walla banda kam stops mei kaam krke gayaa hogaaaaaaaaa 







//YARR BHENCHOD ABHIII FEEL AYYYII HUII HAI QUESTION MEIII FOR AGAR FEEL NI ARRII KYA HORA HAI TOH STRIVER KI VIEDO DEKHLLEEE


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
int len=flights.size();
for(int i=0 ;i< len ;i++ ){
     int u=flights[i][0];
     int v=flights[i][1];
     int wt=flights[i][2];
     adj[u].push_back({v, wt});
}
k++;                 //kyuki question mei sirf starting or ending node ke bich wallo ko stop bola hua hai or maine destination ko bhi as a stop consider kia huaa haiii
vector<int> distance(n,INT_MAX);
int ans=INT_MAX;
queue<pair<int,pair<int,int>>> q;              //no. of nodes that we have traveled , node , distance
q.push({0,{src,0}});
while(!q.empty()){
    pair<int,pair<int,int>> p = q.front();
    q.pop();
    int node=p.second.first;
    int dist=p.second.second;
    int temp_k=p.first;
    if(p.second.first==dst)ans=min(ans, p.second. second); // agar 

    if(temp_k==k)continue;


    for(auto i: adj[node]){
        if(dist+i.second < distance[i.first]){
            distance[i.first]=dist+i.second;
        q.push({temp_k+1, {i.first, distance[i.first]}});                 
        }
    }
    
}

if(ans==INT_MAX){
    return -1;
}


return ans;
    }
};






int main(){
    
    return 0;
}