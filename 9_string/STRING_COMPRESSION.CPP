#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
    int i=0;
    int ansindex=0;
    int n=chars.size();
        while(i<n){
                    int j=i+1;
        while(j<n && chars[i]==chars[j]){
            j++;
        }
        // yah toh vector pura transfer krlliyya
            // ya fir character change karliya
//old char save        
        chars[ansindex++]=chars[i];
        int count =j-i;
        if(count>1){
            string cnt=to_string(count);
            for(char ch: cnt)    //for(char ch belongs to count )
            {
               chars[ansindex++]=ch; 
            }
        }
            i=j;
        }
        

        return ansindex;
    }
};
int main(){
    
    return 0;
}