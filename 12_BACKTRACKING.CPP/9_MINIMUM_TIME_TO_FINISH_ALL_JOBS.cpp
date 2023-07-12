
/*
You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.

There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.

Return the minimum possible maximum working time of any assignment.

 

Example 1:

Input: jobs = [3,2,3], k = 3
Output: 3
Explanation: By assigning each person one job, the maximum time is 3.
Example 2:

Input: jobs = [1,2,4,7,8], k = 2
Output: 11
Explanation: Assign the jobs the following way:
Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
Worker 2: 4, 7 (working time = 4 + 7 = 11)
The maximum working time is 11.
 

Constraints:

1 <= k <= jobs.length <= 12
1 <= jobs[i] <= 107
*/


//NUMBER OF WAYS TO ASSIGN N JOBS TO K WORKERS
//PURE BACKTRACKING SOLUTION GIVES TLE SO WE OPTIMIZE IT A BIT TO PREVENT UNNECESARRY CALLS


/*
It is a backtracking problem where we have to try different combinations of given N numbers to fill all K buckets.
Once we're done filling all the K buckets with these numbers, we need to find the bucket which has maximum sum. This sum is a vaild answer or not ? To check this:
We have to store the minimum of all such sum after trying out all combinations.
Each number is going to be in one of the given K buckets, i.e. no number left unused.
ALGORITHM
Sort the jobs vector in descending order.
Create a backtracking function with arguments (jobIndex, totalWorkers, JobVector).
Create a workTime vector of size K to track the time taken by j th worker to finish his/her assigned jobs.
Base case: when jobIndex == JobVector.size() , i.e. all the jobs has been completed so our answer is going to be min(globeAns, currentCombinationAnswer)
currentCombinationAnswer is *max_element(workTime.begin(),workTime.end())
Now the important part: To avoid TLE we'll do 2-3 lines of modification in our backtracking function.
Modification 1 : If globeAns <= max_element(workTime.begin(),workTime.end()) at any recurring state then we can return because it ain't going to give us an optimal answer, as workTime of some workers is exceeding our previous minimal answer.
Modification 2 : if workTime[j] >= workTime[j - 1] for all j > 0 , then we should avoid adding newJob to j th worker , we'll continue in this case as it's not optimal to add to workTime[j] as it's already bigger.
These modifications going to cut off all unnecessary recursion calls.
else we'll simply take ith job for the current worker and call a DFS for (jobIndex + 1, totalWorkers, JobVector) and backtrack by removing ith job from the current worker's workTime cell.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int ans = INT_MAX;
vector<int>work;


void solveBackTrack(int i,int k,int n,vector<int>&jobs){
    //if we completely traversed the array then updating the anwer 
    if(i == n){
        int maxi = *max_element(work.begin(),work.end());
        ans = min(ans,maxi);
        return ;
    }


    //if max element in my current array is greater than answer then no need to process
    if(*max_element(work.begin(),work.end()) >= ans)
        return;


        
    for(int j = 0; j < k; j++){
        if(j > 0 and work[j] >= work[j - 1])continue;
        work[j] += jobs[i];
        solveBackTrack(i+1,k,n,jobs);
        work[j] -= jobs[i];
    }
    return ;
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    //sorted jobs in decreasing order
    sort(jobs.begin(),jobs.end(),greater<int>());
    int n = jobs.size();
    if(n == k)return jobs[0];
    work.resize(k,0);
    solveBackTrack(0,k,n,jobs);
    return ans;
}
};


int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}