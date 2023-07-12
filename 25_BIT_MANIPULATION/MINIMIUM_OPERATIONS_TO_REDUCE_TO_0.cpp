/*
You are given a positive integer n, you can do the following operation any number of times:

Add or subtract a power of 2 from n.
Return the minimum number of operations to make n equal to 0.

A number x is power of 2 if x == 2i where i >= 0.

 

Example 1:

Input: n = 39
Output: 3
Explanation: We can do the following operations:
- Add 20 = 1 to n, so now n = 40.
- Subtract 23 = 8 from n, so now n = 32.
- Subtract 25 = 32 from n, so now n = 0.
It can be shown that 3 is the minimum number of operations we need to make n equal to 0.
Example 2:

Input: n = 54
Output: 3
Explanation: We can do the following operations:
- Add 21 = 2 to n, so now n = 56.
- Add 23 = 8 to n, so now n = 64.
- Subtract 26 = 64 from n, so now n = 0.
So the minimum number of operations is 3.
 

Constraints:

1 <= n <= 105

*/



// approach is bits mei break karlooo or fir jo ek sathh walle ones hai unka ek one ban jayeega jus by adding one to them  or fir jo one bana uskoo remove karnnnaa haiii bas yahi question ka sarr haii


#include<bits/stdc++.h>
using namespace std;


class Solution {
   

public:
    int minOperations(int n) {
        
        int num1=n;
        vector<int> bits;


        while(n){
            bits.push_back(n%2);
            n/=2;
        }





        int ans=0;
        int i=0;

        for(auto bit:bits){
            cout<<bit<<",";
        }

        bits.push_back(0);
        bits.push_back(0);
        bits.push_back(0);
        bits.push_back(0);

        int len=bits.size();


        while(i<len){
        
            // cout<<bits[i]<<",";

            if(bits[i]==1){
                ans+=1;
        
            i++;
            if(bits[i]==1){  
            while(bits[i]==1){
                i++;
            }
                bits[i]=1;
            }
            }
            else{
                i++;
            }
        }


return ans;



        
    }
};

int main(){

    
    return 0;
}