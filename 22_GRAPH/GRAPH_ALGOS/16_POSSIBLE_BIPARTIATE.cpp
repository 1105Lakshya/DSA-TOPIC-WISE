/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
*/

//THIS CAN ALSO BE SEEN AS 2-COLORING PROBLEM WHICH IS THAT CAN WE COLOR GRAPH WITH 2 COLORS SUCH THAT NO TWO ADJACENT NODE HAVE SAME COLORS
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto i: dislikes){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<pair<bool,bool>> visited(n+1 ,{false,false});


        for(int k=1 ;k<=n ;k++){
            if(!(visited[k].first)){

            
         queue<pair<int,bool>> q;       //true means one color false means another color
        q.push({k,true});
        visited[k]={true,true};

        while(!q.empty()){
            pair<int,bool> node=q.front();
            q.pop();
            bool color=node.second;
            int val =node.first;

            for(auto i: adj[val]){
                if(!visited[i].first){
                   q.push({i,!(color)}) ;
                   visited[i]={true,!(color)};
                }
                else{
                    if(visited[i].second==color){
                        return false;
                    }
                }
            }

        }
            }    
        }
       
return true;

    }
};



int main(){

    return 0;
}