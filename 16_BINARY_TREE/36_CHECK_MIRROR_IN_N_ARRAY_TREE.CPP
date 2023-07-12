/*
Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.


Example 1:

Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 3, 1, 2}
Output:
1
Explanation:
   1          1
 / \        /  \
2   3      3    2 
As we can clearly see, the second tree
is mirror image of the first.
Example 2:

Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 2, 1, 3}
Output:
0
Explanation:
   1          1
 / \        /  \
2   3      2    3 
As we can clearly see, the second tree
isn't mirror image of the first.



*/



//first array mei iterate krke har node ke corresponding child ka stack bann liyyyaa
//second array mei itereate krek corresponding stack ke top se compare krte rahhe or pop marr te rahhhee
//recommended see alisha  youtube viedooo 



/*

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int ,stack<int> > map;
        int curr=0;
        int prev=curr;
        for( int i=0;i< 2*e; i+=2){
        map[A[i]].push(A[i+1]);
        }
        
        for(int i=0;i<2*e;i+=2){
            if(map.find(B[i])==map.end())
            return 0;
            else{
                auto it=map.find(B[i]);
                if((it->second).top()!=B[i+1])
                return false;
                else
                (it->second).pop();
            }
            
        }
        return true;
    }
};




*/