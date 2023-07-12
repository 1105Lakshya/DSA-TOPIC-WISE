#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void solve(string digits,string output,int index,vector<string>& ans,string mapping[]){
    if(index>=digits.size()){
        if(output.size()>0)
        ans.push_back(output);
        return;
    }
    char c=digits[index];
    int num=c-'0';
    string str=mapping[num];
    int n=str.size();
    for(int i=0;i<n;i++){
        output.push_back(str[i]);
        solve(digits,output ,index+1,ans,mapping);
        output.erase(output.size()-1,output.size());
    }
    
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        int index=0;
        string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output ,index,ans,mapping);
        return ans;
    }
};
int main(){
    Solution a;
    vector<string> c;
    c= a.letterCombinations("23");
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<endl;
    }
    
    return 0;
}