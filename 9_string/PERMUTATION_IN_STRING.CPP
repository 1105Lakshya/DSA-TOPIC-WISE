// **************************************************LEETCODE*************************************************************************

/*

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool checkequal(int a[26],int b[26]){
        
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            count1[index]++;
        }
        int i=0;
        int windowsize=s1.length();
        int count2[26]={0};
        
        
        while(i<windowsize){
            int index =s2[i]-'a';
            count2[index]++;
            i++;
        }
        if(checkequal(count1,count2)){
            return 1;
        }
        
        
        while(i<s2.size()){
            char newchar=s2[i];
            count2[(newchar-'a')]++;
            char oldchar=s2[i-windowsize];
            count2[oldchar-'a']--;
            if(checkequal(count1,count2)){
                return true;
            }
            i++;
        }
        return false;
    }
};


int main(){
    
    return 0;
}