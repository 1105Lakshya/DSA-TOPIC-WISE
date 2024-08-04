





/*

Q-> FIND MINIMUM TIME A HAS TO REPEAT ITSELF SO THAT B IS A SUBSTRING OF A

Input:
A = "abcd"
B = "cdabcdab"
Output:
3
Explanation:
Repeating A three times (“abcdabcdabcd”),
B is a substring of it. B is not a substring
of A when it is repeated less than 3 times.
Example 2:
Input:
A = "ab"
B = "cab"
Output :
-1
Explanation:
No matter how many times we repeat A, we can't
get a string such that B is a substring of it.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lena=a.length();
        int lenb=b.length();


        //initalized two pointers at starting of both the strings
        
        for(int s=0;s<lena;s++){
            int i=s;
            int repeats=0;
            for(int j=0;j<lenb;j++){
                if(a[i]==b[j]){
                    i++;
                    if(i==lena){
                        i=0;
                        repeats++;
                    }
                }
                else{
                    break;
                }


                if(j==lenb-1){
                    return i!=0?repeats+1:repeats;
                }
            }
        }


        return -1;
        
        
    }
};