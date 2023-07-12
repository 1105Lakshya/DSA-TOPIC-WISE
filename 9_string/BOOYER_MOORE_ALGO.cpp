/*
SEE BHARTI MAM VEIDO ON YOUTUBE
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	string txt;
	cout<<"ENTER THE TEXT "<<endl;
	cin>>txt;
	string pat;
	cout<<"ENTER THE PATTERN "<<endl;
	cin>>pat;

	int n=txt.size();
	int m=pat.size();
	vector<int> bdmt(26, m);         // bdmt stand for bad match 

	for(int i=0;i<m;i++){
		int index=pat[i]-'a';
		bdmt[index]=m-i-1;
	}
	bdmt[pat[m-1]-'a']=m;
    int count=0;
	int s=0;
	while(s+m-1<n){
		int j=s+m-1;
		int i=m-1;
		if(txt[j]!=pat[i]){
		s+=bdmt[txt[j]-'a'];
		continue;
		}

		while(i>=0 && txt[j]==pat[i]){
			j--;
			i--;
		}
		if(i<0){
			cout<<"PATTERN OCCURS AT "<<s<<" INDEX"<<endl;
			s+=m;
		}
		else{
			s+=bdmt[txt[j+1]-'a'];
		}
	}

    cout<<"TOTAL NUMBER OF COMPARISONS ARE "<<count;
	return 0;
}
