/*
You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.

 

Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
Example 2:

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
1 <= lefti <= righti <= 106
*/

#include<bits/stdc++.h>
using namespace std;


class Solution1{
public:
    int minGroups(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),compare);
    int n=intervals.size();
        priority_queue<int ,vector<int> , greater<int> > pq;
        pq.push(intervals[0][1]);
        for(int i=1 ;i<n;i++){
            if(pq.top()<intervals[i][0]){
                pq.pop();
            }
                pq.push(intervals[i][1]);
        }
        
        return pq.size();
    }
};

//GREEDY METHOD 
//SEE ANUJ BHAIYAA MINIMUM PLATFORM VIEDO
//SIMILAR TO PROBLEM MINIMUM NUMBER OF PLATFORMS
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> arrival;
        vector<int> departure;
        for(int i=0;i<n;i++){
            arrival.push_back(intervals[i][0]);
            departure.push_back(intervals[i][1]);
        }
        
        sort(arrival.begin(),arrival.end());
        sort(departure.begin(),departure.end());
        
        int count=0;
        int maxCount=0;
        int i=0;
        int j=0;
        while(i<n){
            if(arrival[i]<=departure[j]){
                count++;
                maxCount=max(maxCount,count);
                i++;
                continue;
            }
            else{
                count--;
                j++;
            }
        }
        
        
        return maxCount ;
    }
};






int main(){
    
    return 0;
}