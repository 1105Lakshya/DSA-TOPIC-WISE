//QUESTION
/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500
*/

//APPROACH
/*
Here we will sort the array on the basis of profit then we will start traversing the array from beginiing and will perform the job at the most max time for this we will
start traversing from its deadline in backward direction  and as soon as we find the first khalli space  we will perform the job there  if we reach the end of the array then it means there
is no blank space from that particular deadline so we will mark its second as 0 indicating that there is no blank space furthur so stop iterating 
*/






//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    
    
    static bool cmp(Job a, Job b){
        if(a.profit >  b.profit){
            return true;
        }
        return false;
    }
    
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {   
        int jobsdone=0;
        int maxprofit=0;
        vector<pair<int,int>> job(n+1,{0,1});
        sort(arr ,arr+n , cmp);

        for(int j=0 ;j< n;j++){
            int deadline=arr[j].dead;
            int munafaa=arr[j].profit;
            int t;
            if(deadline>n){   //if deadline is greater than n then we will traverse entire array
                t=n;
            }else{
                t=deadline;
            }
            
                for(int i=t ;i>=0;i--){
                    if(i==0){
                        job[deadline].second=0;
                        break;
                    }
                    if(job[i].first ==0){
                        job[i].first=1;
                        jobsdone++;
                        maxprofit+=arr[j].profit;
                        break;
                    }
                    if(job[i].second==0){
                        job[deadline].second=0;
                        break;
                    
                    }
                }
            
        }
    vector<int> ans;
    ans.push_back(jobsdone);
    ans.push_back(maxprofit);
    return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends