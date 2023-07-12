#include<bits/stdc++.h>
using namespace std;

// NOTE:IF WE WANT TO PASS AN 2D ARRAY TO FUNCTION THEN SPECIFYING THE NUMBER OF COLUMNS  IS MANDATORY

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix[0].size();
        int n=matrix.size();
            int row_start=0;
        int size=m*n;
    int row_end=n-1;
    int column_start=0;
    int column_end=m-1;
        int count=0;
    while(count < size){
        // for row start
        for(int col=column_start;count <size && col<=column_end;col++){
            ans.push_back(matrix[row_start][col]);
            count++;
        }
        row_start++;
        //for column end

        for(int row=row_start;count <size && row<=row_end;row++){
            ans.push_back(matrix[row][column_end]);
            count++;
        }
        column_end--;
        
        // for row_end

        for(int col=column_end;count <size && col>=column_start;col--){
            ans.push_back(matrix[row_end][col]);
            count++;
        }
        row_end--;

        // for column_start

        for(int row=row_end ;count <size && row>=row_start;row--){
            ans.push_back(matrix[row][column_start]);
            count++;
        }
        column_start++;

        }
        return ans;
    }
};

int main(){
    // int n,m;
    // cin>>n>>m;
    // int a[n][m];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>a[i][j];
    //     }
    // }
    // // spiral order print
    // int row_start=0;
    // int row_end=n-1;
    // int column_start=0;
    // int column_end=m-1;
    // while(row_start<=row_end && column_start<=column_end){
    //     // for row start
    //     // cout<<"printing row start: "<<row_start<<endl;
    //     for(int col=column_start;col<=column_end;col++){
    //         cout<<a[row_start][col]<<" ";
    //     }
    //     cout<<endl<<endl;
    //     row_start++;
    //     //for column end
    //     // cout<<"printing column end: "<<column_end<<endl;

    //     for(int row=row_start;row<=row_end;row++){
    //         cout<<a[row][column_end]<<" ";
    //     }
    //     column_end--;
    //     cout<<endl<<endl;
        
    //     // for row_end
    //     // cout<<"printing row start :"<<row_start<<endl;

    //     for(int col=column_end;col>=column_start;col--){
    //         cout<<a[row_end][col]<<" ";
    //     }
    //     row_end--;
    //     cout<<endl<<endl;

    //     // for column_start
    //     // cout<<"printing column start: "<<column_start<<endl;

    //     for(int row=row_end ;row>=row_start;row--){
    //         cout<<a[row][column_start]<<" ";
    //     }
    //     column_start++;
    //     cout<<endl<<endl;

    //     }
    return 0;
}