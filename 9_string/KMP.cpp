// C++ program for implementation of KMP pattern searching
// algorithm watch tech dose
#include<bits/stdc++.h>
using namespace std;



//lakshya version
class Solution {
    vector<int> make_lps(string pat){
        int len=pat.length();

        vector<int> lps(len,0);

        int j=0; // watch tech dose video and then see the code 
        int i=1;
        while(i<len){
            if(pat[i]==pat[j]){
                j++;
                lps[i]=j;
                i++;
            }

            else if(j!=0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }

        return lps;
}
public:
    int strStr(string pat, string text) {
        int len1=text.length();
        int len2=pat.length();
        int ans=0;
        vector<int> lps=make_lps(pat);

        int i=0;
        int j=0;
        while(len1-i >= len2-j){  // jab tak bachi hui length in txt is greater than bachi hui length in pattern

        while(j<len2 && text[i]==pat[j]){
            i++;
            j++;
        }
        if(j==len2){
            ans++;
            // printf("Found pattern at index %d ", i - len2);
            
            j = lps[j - 1];
        }
        else if(j!=0){
            j=lps[j-1];
        }
        else{
            i++;
        }
        }

        return -1;
        
    }
};










//GFG VERSION 
void computeLPSArray(char* pat, int M, int* lps);
 
// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
 
// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
// Driver code
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
