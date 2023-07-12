/*
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

 

Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
 

Constraints:

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
All the values of routes[i] are unique.
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        unordered_map<int,vector<int>>bus;
        for(int i=0;i<routes.size();++i)
        {
            for(auto stop:routes[i])
            {
                bus[stop].push_back(i); //each stop's buses
            }
        }
        vector<bool>bus_taken(routes.size());
        queue<int>q;
        for(auto take:bus[source])  //taking all buses of source stop
        {
            bus_taken[take]=1;
            q.push(take);
        }
        int ans=0;
        while(!q.empty())
        {
            ++ans;
            for(int s=q.size();s>0;--s)
            {
                int current=q.front(); //current bus
                q.pop();
                for(int route:routes[current]) //all routes of current bus
                {
                    if(route==target)return ans;
                    for(int i=0;i<bus[route].size();i++) //all buses of current stop
                    {
                        if(!bus_taken[bus[route][i]]) //checking if the bus of current stop is taken
                        {
                            bus_taken[bus[route][i]]=1;
                            q.push(bus[route][i]);
                        }
                    }
                }
            }
        }
        return -1;
    }
};



int main(){
    
    return 0;
}