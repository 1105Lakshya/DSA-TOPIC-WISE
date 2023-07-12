/*
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

 

Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 
Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
 

Constraints:

1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
All the values of starti are unique.


*/



#include<bits/stdc++.h>
using namespace std;



//created min heap and if equal then the index with lower prefer is on top
class cmp{
    public:
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        if(a.first > b.first)return true;
        if(a.first<b.first)return false;

        return a.second > b.second;
    }
};


//created min heap and if equal then the index with lower prefer is on top
class cmp2{
    public:
    bool operator()(pair<long long ,int> &a, pair<long long ,int> &b){
        if(a.first > b.first)return true;
        if(a.first<b.first)return false;

        return a.second > b.second;
    }
};


class Solution{
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        //count array to store count of meetings
        vector<int> count(n,0);
        sort(meetings.begin(),meetings.end());


        //priority queueto store empty rooms
        priority_queue<pair<int ,int> , vector<pair<int,int>> , cmp> pq1; //to store empty rooms 

        priority_queue<pair<long long ,int> , vector<pair<long long,int>> , cmp2> pq2; //to store rooms that are booked


        //pushed 1 to n-1 rooms in emtpy
        for(int i=1;i<n;i++){
            pq1.push({0,i});
        }


        //index0 meeting will always be held in room number 0 
        pq2.push({meetings[0][1],0});
        count[0]++;

        int j=0;
        int len=meetings.size();

        for(int i=1;i<len;i++){
            long long int starttime=meetings[i][0];

            //removed the meetings who has end time less than the start time of current meeting
            while(!pq2.empty() && pq2.top().first<=starttime){
                pq1.push({0,pq2.top().second});
                pq2.pop();
            }



            //if any room empty poped from empty and pushed to booked rooms with end time of current meeting endtime
            if(!pq1.empty()){
                pair<long long ,int> p=pq1.top();

                pq1.pop();

                pq2.push({meetings[i][1],p.second});
                count[p.second]++;
                continue;
            }

            //took the smallest end time and then did the meeting at this room and end time will be the time at which the most recent meeting will end + the time taken for current meeting 
            else{

            pair<long long ,int> p=pq2.top();
                count[p.second]++;
                p.first+=meetings[i][1]-meetings[i][0];
                pq2.pop();
                pq2.push(p);
            }


        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(count[i]>count[ans]){
                ans=i;
            }
        }

      
    
    return ans;
    }
};

int main(){

    
    return 0;
}