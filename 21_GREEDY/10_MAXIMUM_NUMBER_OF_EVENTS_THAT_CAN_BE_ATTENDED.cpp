/*


You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.

 

Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
 

Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105


*/


//greeddy is that sort on basis of start timee and attend that even first who has end time sooneerrrrrrrr


#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        int n=events.size();
        //priority queue contains deadlines of all the events
        //that have already started but not ended
        priority_queue<int,vector<int>,greater<int>> pq;
        
        //sort by event start time
        sort(events.begin(),events.end());
        int ans=0;
        int i=0;
        for(int d=1;d<=100000;d++)
        {
          
            //remove all the events which are already over
            while(!pq.empty()&&pq.top()<d)
            {
                pq.pop();
            }
             
            //insert deadlines of all events that start today
            while(i<n && events[i][0]==d  )
            {
                pq.push(events[i][1]);
                i++;
            }
            //if there are any events we can attend today we 
            //attend the event with smallest endtime
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
            
             //if all elements are processed then stop 
            if(pq.empty()&&i==n)
                break;
        }
        return ans;
    }
};


