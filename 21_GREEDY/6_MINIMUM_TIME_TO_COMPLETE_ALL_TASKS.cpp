/*
There is a computer that can run an unlimited number of tasks at the same time. You are given a 2D integer array tasks where tasks[i] = [starti, endi, durationi] indicates that the ith task should run for a total of durationi seconds (not necessarily continuous) within the inclusive time range [starti, endi].

You may turn on the computer only when it needs to run a task. You can also turn it off if it is idle.

Return the minimum time during which the computer should be turned on to complete all tasks.

 

Example 1:

Input: tasks = [[2,3,1],[4,5,1],[1,5,2]]
Output: 2
Explanation: 
- The first task can be run in the inclusive time range [2, 2].
- The second task can be run in the inclusive time range [5, 5].
- The third task can be run in the two inclusive time ranges [2, 2] and [5, 5].
The computer will be on for a total of 2 seconds.
Example 2:

Input: tasks = [[1,3,2],[2,5,3],[5,6,2]]
Output: 4
Explanation: 
- The first task can be run in the inclusive time range [2, 3].
- The second task can be run in the inclusive time ranges [2, 3] and [5, 5].
- The third task can be run in the two inclusive time range [5, 6].
The computer will be on for a total of 4 seconds.
 

Constraints:

1 <= tasks.length <= 2000
tasks[i].length == 3
1 <= starti, endi <= 2000
1 <= durationi <= endi - starti + 1 

*/


//greedy ismei ye hai ki hum apne task ko aggar humare range mei kahi task pehle ho rakha hai toh hume waha karenge nahi toh hum apni range mei jo bache hue task hai unko bilkul range ke end mei karenge taki maximum chance ho ki next range walla koi is se coincide karee or humare on hone ka time minimum ho uske liye humne ek 2000 length ki array banali and then we used for marking in which region task was done or humne ismei end time ke basis pe sort bhi karli


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        bool timeOn[2001] = {};
        // Sorting on the basis of 'End time'
        sort(begin(tasks), end(tasks), [](const auto &t1, const auto &t2){
            return t1[1] < t2[1];
        });

        for(auto &task : tasks){
            int start=task[0], end=task[1], duration=task[2];
            for(int i=start;i<=end;i++) if(timeOn[i]) duration--;
            for(int i=end;duration>0;i--){
                if(timeOn[i]) continue;   // agar on hai toh hum already count kar chuke honge 
                duration--;
                timeOn[i] = true;
            }
        }

        int countTimeOn = 0;
        for(int i=1;i<=2000;i++) countTimeOn += timeOn[i];
        return countTimeOn;
    }
};


int main(){
    
    return 0;
}