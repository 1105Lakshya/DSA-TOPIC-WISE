#include<bits/stdc++.h>
using namespace std;

void solve(int n, int source,int helper ,int destination ,vector<vector<int >>& ans){
    //agar n=1 ho toh bas source se uthakke destination pe rakhdodoooo  
    //base case
	if(n==1){                
		vector<int> temp;
		temp.push_back(source);
		temp.push_back(destination);
		ans.push_back(temp);
		return;
	}

    //uppar ke n-1 humnne helper pe uthhhake rakhdiyyeeee
	solve(n-1,source,destination,helper, ans);

    //fir akkhriii walee ko  source se destination pe rakhhdiyyyaa 
	vector<int> temp;
	temp.push_back(source);
	temp.push_back(destination);
	ans.push_back(temp);

    //fir n-1 walle jo helper pe raakhhhee theee unhe uthhhakkee destination pe rakkkhhdiyyaaa
	solve(n-1,helper,source,destination, ans);
	
	}




vector<vector<int>> towerOfHanoi(int n)
{
	int source=1;
	int helper=2;
	int destination =3;
	vector<vector<int>> ans;
	solve(n,source,helper,destination ,ans);
	return ans;
}


int main(){
    
    return 0;
}