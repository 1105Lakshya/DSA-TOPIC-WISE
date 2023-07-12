//QUESTION

/*

The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.
A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses. Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.
For Example
In the below map of Ninjaland let say you want to go from S=1 to T=8, the shortest path is (1, 3, 8). You can also go from S=1 to T=8  via (1, 2, 5, 8)  or (1, 4, 6, 7, 8) but these paths are not shortest.

Input Format :
The first line of input will have a single positive integer ‘T’, denoting the number of test cases. 

The first line of each test case has two positive integers ‘N’ and ‘M’ denoting the number of houses and the number of roads in the ninja land.

The second line contains two integers ‘S’ and ‘T’ denoting the starting and ending house in the path.

Next M lines each contain two integers ‘X’ and ‘Y’. Which denotes a road between house ‘X’ and house ‘Y’.   
Output Format :
You have to return a vector of nodes denoting the shortest path starting from ‘S’ and ending in ‘T’.

If there is more than one shortest path you can return any one of them.

The output of each test case will be "Correct" if you have returned the correct answer, else it will be "Incorrect".

Print the output of each test case in a separate line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function. 
Constraints :
1 <= T <= 100
2 <= N <= 10 ^ 3
1 <= M <= min( N *(N - 1) / 2 , 1000 )
1 <= S, T <= N

Time Limit: 1 sec
Sample Input 1 :
1
4 4
1 4
1 2
2 3
3 4
1 3
Sample Output 1 :
( 1 , 3 , 4 )
Explanation Of Sample Input 1 :
In the above graph there are two ways to go from 1 to 4 ,
( 1 , 2 , 3 , 4 ) and ( 1 , 3 , 4 ) but the second path is the shortest path.

Sample Input 2 :
1
8 9
1 8
1 2
1 3
1 4
2 5
5 8 
3 8
4 6
6 7
7 8
Sample Output 2 :
( 1 , 3 , 8 )


*/








//NOTE----->bfs se hum jab ek node se dusri node pe jatte haii toh shortest path follow kartee huee hi jatttee haiii
//ALGO
/*
WE WILL TRAVERSE THE ARRAY USING BFS TRAVERSAL AND WILL MAKE AN DATA STRUCTURE THAT WILL KEEP TRACK OF PARENT OF ALL THE NODES
THEN WE WILL START FROM THE TARGET NODE AND MOVE BACKWARDS USING THE PARENT TILL WE REACH THE STARTING NODE AND THUS WE WILL HAVE OUR 
SHORTEST PATH
*/


//T.C O(N+E)


#include<bits/stdc++.h>
using namespace std;


//SOLUTION
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	//create adjacency list
    unordered_map<int ,list<int>> adj;
    for(int i=0 ;i< m ;i++){
        int u =edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
 
    }
    
    unordered_map<int,bool> visited;
    unordered_map<int ,int> parent;
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    
    while(!q.empty()){
        int front =q.front();
        q.pop();
        
        for(auto i: adj[front]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
    }
	
    //get shortest path
    vector<int> ans;
    int currentNode= t;
    ans.push_back(currentNode);
    while(currentNode!=s){
        currentNode=parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin() ,ans.end() );
    return ans;
}





int main(){
    
    return 0;
}