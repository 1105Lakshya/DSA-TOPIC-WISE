#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string nums="13242525";
    sort(nums.begin(),nums.end(),greater<int>());
    cout<<nums<<endl;
    int x=stoi(nums);
    cout<<x+0;

    return 0;
}