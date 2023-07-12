#include<iostream>
using namespace std;

int main(){
        int n,m,target;
    cin>>n>>m>>target;
    int matrix[n][m];
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }}
        int r=0,c=m-1;
        bool found =false;
        while(r<n && c>=0){
            if(matrix[r][c]==target){
                found= true;
            }
            if(matrix[r][c]>target){
                c--;
            }
            else{
                r++;
            }
        }
        if(found)
        cout<<"Element foumd"<<endl;
        else{
            cout<<"element not found";
        }
    return 0;
}
