/*

We need a subarray say from i to j such that sum of all elements is divisible by k.

sum_j means prefix sum from 0 to j

sum_i means prefix sum from 0 to i

 => (sum_j - sum_i) % k = 0
 => sum_j % k - sum % k = 0
 => sum_j % k = sum_i % k    <Relation derived !!!>

*/






#include<bits/stdc++.h>
using namespace std;



int subArrayCount(vector<int> &arr, int k) {
    int n=arr.size();
    vector<long long int>  psum(n+1);
    psum[0]=0;
    for(int i=0;i<n;i++){    //prefix sum subarray 
        psum[i+1]=psum[i]+arr[i];
    }
    for(int i=0;i<n+1;i++){ //replacing the character with their modulus
        int num=psum[i]%k;
        num+=k;                                     //if negative  then -2%5  ==  -2 so for converting that added k and then again took the modulus
        psum[i]=num%k;
    }
    

    long long  int count=0;
    unordered_map<int,int> check;
    check[0]++;
    for(int i=1;i<n+1;i++){
        if(check.find(psum[i])!=check.end()){
            count+=check[psum[i]];
        }
        check[psum[i]]++;
    }
    return count;
}

int main(){
    
    return 0;
}