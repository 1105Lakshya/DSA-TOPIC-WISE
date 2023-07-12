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


//EXPLANATION
/*
Each event is described as events[i] = [startDayi, endDayi].
On any day we can attend only one event.
So on each day d we have to choose an optimal event among events that are going on that day i.e. amongst all events such that {startTimei <= d <= endTimei}
So on any day out of all events that are going on we choose the event that is going to end soon because for other events that are going on ,we might get a chance to visit them later( but not always, in case we do not get the chance to visit other events we will anyway lose one event).
For keeping track of ending times of ongoing events we use a priority queue.
If there are no meetings going on a particular day, we don't attend any meeting.
*/

/*
basically here greedy is that we will attend even on basis of who is getting finished first to get who is getting finished first we are using a priority queue 
*/



#include<bits/stdc++.h>
using namespace std;


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

int main(){
    
    return 0;
}
