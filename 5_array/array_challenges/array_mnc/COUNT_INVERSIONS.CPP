/*****************************DSA SHEET ***************************/

long long merge(int arr[], int l,int mid,int r){
    long long inv=0;
    int n1=mid-l+1;
    int n2=r-mid;      //r-(mid+1) +1
    int a[n1];
    int b[n2];        //temp arrays of merge sort
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid +1+i];
    }
    int i=0,j=0,k=l;      //i for left part walli array          // j for right part walli array              // k for orignal array 
    while(i<n1 and  j<n2){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            inv+=n1-i;       // agar a[i] badda haii toh a[i] kee agee walle bhi toh bade hongeeee kyuki array sorted haiii 
            k++;
            j++;
        }
    }
    while(i<n1){            //bacche huee ko merrge krdiyyaa
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2){            // bachee hue ko merge krdiyya
        arr[k]=b[j];
        k++;
        j++;
    }



    return  inv;
}


long long int mergeSort(int arr[],int l,int r){
    long long inv=0;
    if(l<r){
        int mid=l+(r-l)/2;
        inv+= mergeSort(arr,l,mid);         // left walle part mei kiite inversion haii
        inv+=mergeSort(arr,mid+1,r);        // right wallle part mei kitte inversion haiii
        inv+=merge(arr,l,mid,r);            // dono ko merge kiyaa toh usmeii kitte inversion haii
    }
return inv;
}


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<< mergeSort(arr,0,n-1);
    return 0;
}