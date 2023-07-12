//ALGO   N(log(N))
/*
1---> Swap the element at first place with the last coz we know the first value will be greatest due to MAX HEAP and size-- 
2---> Swap hooke jo element shuruaat mei pahuchha uskkoo sahii jagga pahuchhaadoooo  
and continueeeee

*/





#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){             // n is the size of heap
    int largest = i;             // i is the index for and below which we have to convert the tree into min heap
    int left = 2*i;
    int right =2*i+1;

    if(left<=n &&  arr[largest ]< arr[left]){            // checking if child lies within range and comparing value with child
    largest=left;
    }
    if(right <= n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest != i ){           // checking if  largest is updated or not 
    swap(arr[largest] , arr[i]);     //if updated then we have to swap the values for converting the tree into heap
    heapify(arr , n , largest );        // humnee kahha neeche wallle bacche huue tree mei bhii  jo swap honne ke baad value pahuchi hai usko sahi jagga pahucha doo toh recursive call
    }

}


void heapSort( int arr[] , int n){
    int size =n;
    while(size> 1) {
        //step 1
        swap(arr[size] , arr[1]);

        //step 2
        size--;

        //step 3
        heapify(arr ,size ,1);
    }

}



int main(){
    int arr[6]= {-1, 54,53 ,55 ,52 ,50};
    int n=5;

    //creation of heap
    for(int i=n/2 ; i>0 ;i--){                // sirf first n/2 nodes process kareeengiii  kyukiii bakki ki leaf nodes hai jo already heap haii so sirf shuruaat walliiyoo ko heapify krnna
    heapify(arr, n , i);
    }


    
    cout<<"printing the array now "<<endl;
    for(int i=1 ;i<= n;i++){
        cout<<arr[i]<< " ";
    }cout<<endl;
    
    // sorting a heap
    heapSort(arr ,n);

    cout<<"printing the array now "<<endl;
    for(int i=1 ;i<= n;i++){
        cout<<arr[i]<< " ";
    }cout<<endl;



    return 0;
}