//TYPES OF GRAPH              #1 UNDIRECTED GRAPH            #2 DIRECTED GRAPH
//NOTE 
/*
In undirected graph a we can say u and v have a edge as well as we can say v and u have a edge while in directed graph a is to b have a edge
but b is to a does not have a edgeeeee.
*/
// DEGREE OF A NODE IN UNDIRECTED GRAPH  IS THE NUMBERR OF NODES TO WHICH A PARTICULAR NODE IS CONNECTED

//THERE ARE TWO TYPES OF DEGREES IN DIRECTED GRAPH        
//#1 IN DEGREE-->NUMBER OF  INCOMING ARROWS IN png FILE
//#2 OUT DEGREE-->NUMBER OF OUTGOING ARROWS IN png FILE   

//NOTE
/*
IF WEIGHT OF EDGES IS NOT GIVEN THEN WE CAN ASSUME THAT THE WEIGHT IS ONE
*/

//PATH
/*
sequeuce of nodes in which each node is visited ones
*/

//TYPES OF GRAPH REPRESENTATION
/*
1->  ADJACENCY MATRIX
# Number of nodes
# Number of edges

2->  ADJACENCY LIST

*/




#include<bits/stdc++.h>
using namespace std;
template <typename T> 

class graph{
    public:
    unordered_map<T ,list<T> > adj;
    void addEdge(T u ,T v ,bool direction){
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph


        //create an edge from u to v
        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<< j<< " ,";
            }cout<<endl;
        }
    }

};


int main(){

    int n;
    cout<<" Enter the number of nodes"<<endl;
    cin>>n;

    
    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;
    
    graph<int>  g;

    for(int i=0 ;i<m;i++){
        int u,v;
        cin>>u >> v;
        //Creating an undirected graph
        g.addEdge(u,v,0);
    }


    //printing graph
    g.printAdList();
    
    return 0;
}