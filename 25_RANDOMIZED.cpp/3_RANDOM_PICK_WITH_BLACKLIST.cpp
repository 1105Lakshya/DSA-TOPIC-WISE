/*
You are given an integer n and an array of unique integers blacklist. Design an algorithm to pick a random integer in the range [0, n - 1] that is not in blacklist. Any integer that is in the mentioned range and not in blacklist should be equally likely to be returned.

Optimize your algorithm such that it minimizes the number of calls to the built-in random function of your language.

Implement the Solution class:

Solution(int n, int[] blacklist) Initializes the object with the integer n and the blacklisted integers blacklist.
int pick() Returns a random integer in the range [0, n - 1] and not in blacklist.
 

Example 1:

Input
["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
[[7, [2, 3, 5]], [], [], [], [], [], [], []]
Output
[null, 0, 4, 1, 6, 1, 0, 4]

Explanation
Solution solution = new Solution(7, [2, 3, 5]);
solution.pick(); // return 0, any integer from [0,1,4,6] should be ok. Note that for every call of pick,
                 // 0, 1, 4, and 6 must be equally likely to be returned (i.e., with probability 1/4).
solution.pick(); // return 4
solution.pick(); // return 1
solution.pick(); // return 6
solution.pick(); // return 1
solution.pick(); // return 0
solution.pick(); // return 4
 

Constraints:

1 <= n <= 109
0 <= blacklist.length <= min(105, n - 1)
0 <= blacklist[i] < n
All the values of blacklist are unique.
At most 2 * 104 calls will be made to pick.
Accepted
36.8K
Submissions
109.9K
Acceptance Rate
33.5%
*/


#include<bits/stdc++.h>
using namespace std;

//basically maine kya kiiaa ki maine na n mei number of blacklist minus karke number mei se random liaaa ab uski probability toh sameee hoogii that is 1/number remaining

//catch ye haii ki mere selected number mei se kuch blacklisted number hongge toh agar wo number ayyengge toh maine kya kia hai unko un number se map kardiia jo number reeject hogyye 
//but they were not blacklistedddd


        //numbers 0 1 2 3 4 5 6     =>>> n=7
        //blacklist  => 2 3 5  
        
        //remain is 4   

        // select is 0 1 2 3 
        //rejected is 4 5 6

        //if 2 is selected it i will return 4 
        // if 3 is selected i will return 6 
class Solution {
    public:
    unordered_map<int,int> mp;
    int valid_nums=0;
    Solution(int n, vector<int>& blacklist) {
        
        set<int> st;
        
        for(auto &x : blacklist) st.insert(x);
		
        valid_nums = n-st.size();
        int idx = valid_nums; 
        
        for(auto &x:st)
        {
            if(x<valid_nums)
            {
                while(st.count(idx)) idx++; 
				mp[x] = idx++;
            }      
        } 
    }
    

    int pick() {
        int ans = rand()%valid_nums;
        
        if(mp.count(ans))
            return mp[ans];
        
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