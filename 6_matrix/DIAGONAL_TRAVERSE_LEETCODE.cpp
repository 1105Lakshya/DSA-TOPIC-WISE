/*

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105


*/


#include<bits/stdc++.h>
using namespace std;


//basically maine border traverse kiaa haii jiski length tot hai which is m+n-1 and border alternately traverse kia haii







class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m=mat.size();
        int n=mat[0].size();
        int tot=m+n-1;


        bool up=true;
        for(int i=1;i<=tot;i++){
            if(up){
                int str,stc;
                if(i<=m){
                    str=i-1;
                    stc=0;
                }
                else{
                    str=m-1;
                    stc=i-m;
                }

                while(str>=0 && stc<n){
                    // cout<<"{"<<str<<","<<stc<<"}"<<endl;
                    ans.push_back(mat[str][stc]);
                    str--;
                    stc++;
                }

        
            }
            else{
                int str,stc;
                if(i<=n){
                    stc=i-1;
                    str=0;
                }
                else{
                    str=i-n;
                    stc=n-1;
                }

                while(str<m && stc>=0){
                    ans.push_back(mat[str][stc]);
                    str++;
                    stc--;
                }

            }
            up=!up;
        }
        return ans;

    }
};

int main(){

    return 0;
}