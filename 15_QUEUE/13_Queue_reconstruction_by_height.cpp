/*
You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

 

Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
Example 2:

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

Constraints:

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.

*/


#include<bits/stdc++.h>
using namespace std;

// People = [[7,0], [4,4], [7,2], [5,0], [6,1], [5,4], [8,0]]
// Sorted People : [[8,0], [7,0], [7,2], [6,1], [5,0], [5,4], [4,4]]]
 
//  man = [8,'0'] -> ans.insert(ans.begin()+'0', man) -> ans  = ["[8,0]"]
//  man = [7,'0'] -> ans.insert(ans.begin()+'0', man) -> ans  = ["[7,0]", [8,0]]
//  man = [7,'2'] -> ans.insert(ans.begin()+'2', man) -> ans  = [[7,0], [8,0], "[7,2]"]
//  man = [6,'1'] -> ans.insert(ans.begin()+'1', man) -> ans  = [[7,0], "[6,1]", [8,0], [7,2]]
//  man = [5,'0'] -> ans.insert(ans.begin()+'0', man) -> ans  = ["[5,0]", [7,0], [6,1], [8,0], [7,2]]
//  man = [5,'4'] -> ans.insert(ans.begin()+'4', man) -> ans  = [[5,0], [7,0], [6,1], [8,0], "[5,4]", [7,2]]
//  man = [4,'4'] -> ans.insert(ans.begin()+'4', man) -> ans  = [[5,0], [7,0], [6,1], [8,0], "[4,4]", [5,4], [7,2]]
 


 //way of thinking should be we need to insert the larger height elements first as insertion of smaller height people does not have any effect on larger height people 

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){ 
        if(a[0] == b[0]) {
            return a[1] < b[1];
        }    
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(), people.end(), comp); 
        vector<vector<int>> ans;  

        for(auto man : people){
            ans.insert(ans.begin()+man[1], man);   
        }
        return ans;
    }
};


int main(){
    
    return 0;
}