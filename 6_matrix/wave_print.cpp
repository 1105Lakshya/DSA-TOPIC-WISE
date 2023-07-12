#include<bits/stdc++.h>
using namespace std;


vector<int> wavePrint(vector<vector<int>> arr, int nrows, int mCols)
{
vector <int> ans;
	for(int col =0;col<mCols;col++){
		//odd index bottom to top 
		if(col&1){
			for (int row =nrows-1;row>=0;row--){
				ans.push_back(arr[row][col]);
			}
		}
		else{
			//0 or even index ->top to bottom
			for (int row =0;row<nrows;row++){
				ans.push_back(arr[row][col]);
			}
		}
		}
return ans;
	}


int main(){
    
    return 0;
}