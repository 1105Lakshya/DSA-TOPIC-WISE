/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

 

Example 1:

Input: n = 13
Output: 6
Example 2:

Input: n = 0
Output: 0
*/



// 7162==> (7000,7162)==> number of ones in this range will be equal to number of ones in 162
//6000-6999 ==> number of ones in 999
//5000-5999 ==> number of ones in 999
//4000-4999 ==> number of ones in 999
//3000-3999 ==> number of ones in 999
//3000-3999 ==> number of ones in 999
//1000-1999 ==> number of ones in 999 + 1000;
//0000-0999 ==> number of ones in 999


//suppose number is 123;
// 123==> 100-123 ==> number of ones will be equal to number of remainder i.e 23
// 0-100 -> number of one will be 1+number of one in 99;

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getdigits(int num){
        int count=-1;
        while(num){
            count++;
            num/=10;
        }

        return count;
    }
    
    int solve(int num){
        if(num==0)return 0;
        if(num<10){
            return 1;
        }
        int num_digits=getdigits(num);

        int div=1;
        while(num_digits--){
            div*=10;
        }

        int remainder=num%div;
        int quotient=num/div;


        int ans=0;
        ans+=solve(remainder);
        if(quotient!=1)
        ans+=div;
        else{
            ans+=remainder;
        }

        if(quotient!=1)
        ans+=quotient * solve(div-1);
        else{
            ans+=1;
            ans+=solve(div-1);
        }

return ans;

    }
public:
    int countDigitOne(int n) {
        if(n==0)return 0;
     int ans=   solve(n);

        return   ans;
    }
};





int main(){
    
    return 0;
}