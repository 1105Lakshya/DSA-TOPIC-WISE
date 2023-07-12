//very fast fater than bubble insertion selection 

// What is the best and worst case time complexity of merge sort?
// O(n*Log n)
// The time complexity of MergeSort is O(n*Log n) in all the 3 cases (worst, average and best) as the mergesort always divides the array into two halves and takes linear time to merge two halves.
// not in place 
// big O of (n) space complexity
#include<iostream>
using namespace std;



// void merge(int *arr,int s,int mid ,int e){

//     int len1=mid -s +1;
//     int len2=e-mid;
//     int *first=new int [len1];
//     int *second=new int [len2];
//     int k=s;
//     for(int i=0;i<len1;i++){
//         first[i]=arr[k++];
//     }
//     //  k=mid+1;
//     for(int i=0;i<len2;i++){
//     second[i]=arr[k++];
//     }
//     // merging
//     int idx1=0;
//     int idx2=0;
//     while(idx1<len1 && idx2 <len2){
//         if(first[idx1]<second[idx2]){
//             arr[s++]=first[idx1++];
//         }
//         else{
//             arr[s++]=second[idx2++];
//         }

//     }
//     while(idx1<len1){         //agar pehllii array mei kuch elements bacchh gyee uske liyyee
//             arr[s++]=first[idx1++];
//     }    
//     while(idx2<len2){                // agar dusri array mei kuch elements bacch gyye uske liye 
//             arr[s++]=second[idx2++];
//     }    
// return;
// }

// }
// void mergeSort(int*arr,int s,int e){
//     //base case
//         if(s>=e){
//         return ;
//     }
//     int mid=(s+e)/2;
//     //left part sort
//     mergeSort(arr,s,mid);

//     // right part sort karna hai
//     mergeSort(arr,mid+1,e);

//     merge(arr,s,e);
//     return;

// }



void merge(int arr[] , int start ,int mid ,int end){
    int n=mid-start+1;
    int temp[n];
    int count=0;
    cout<<endl;
    cout<<start<<" "<<mid<<" "<<end<<endl;
    cout<<"PRINTING THE FIRST OF THE ARRAY "<<endl;
    int k=start;
    for(int i=0;i<n;i++){
        temp[i]=arr[k++];
        cout<<temp[count++]<<",";
    }
    cout<<endl;

    int i=0 ;
    int j=k;
    int m=end-start +1;
    count=start ;
    while(i<n && j< m){
        if(temp[i] <= arr[j]){
            arr[count++]=temp[i++];
        }
        else{
            arr[count++]=arr[j++];
        }
    }


    while(i<n){
        arr[count++]=temp[i++];
    }
    while(j<m){
        arr[count++]=arr[j++];
    }

    cout<<"AFTER MERGING "<<endl;
    for(int i=start ;i<=end;i++){
        cout<<arr[i]<<", ";
    }

cout<<endl;
    return ;
}


void mergeSort(int arr[] , int start ,int end ){

    if(start==end){
        return ;
    }
    if(end-start==1){
        if(arr[start]>arr[end]){
            swap(arr[start],arr[end]);
        }
        return ;
    }


    int mid = (start+end)/2;

    mergeSort(arr,start, mid);

    mergeSort(arr,mid+1,end);


    merge(arr, start ,mid ,end);

    return ;



}

int main(){

    int arr[]={3,4,5,3,2,45};
    mergeSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;


}
