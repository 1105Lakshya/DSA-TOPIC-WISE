//QUESTION
/*
givent the arrival time and departure time of the trains at each platform a single train can stand 
give the minimum number of platforms required for proper arrival and departure of all trains 

*/

//problem in which we need to find maximum number of platformssssssssssss


#include<bits/stdc++.h>
using namespace std;

//GREEDY METHOD 
//SEE ANUJ BHAIYAA MINIMUM PLATFORM VIEDO
//SIMILAR TO PROBLEM MINIMUM NUMBER OF PLATFORMS


//APPROACH 1
/*

we started from the begin and maintained a count variable and a max variable
so we sort our arrival time and departure time separately  and maintain two pointer on both of them and follow the below algo-->
on arrival time we will incremennt the count variable 
on departure we will decrement the count variable
keep udating our max
return max


*/

/*





*/
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