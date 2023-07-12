//HEAPIFY FUNCTION KA KAAM HAII KI EK NODE KO USKKIII SAHI JAGGA PAR LEKKEEE JANNNAAA HEAP MEIIII
//HEAPIFY WALLE FUNCTION MEI JO INDEX PASS KIYYA HUAA HAI US SE NEECHE SABKO HEAP MEI CONVERT KRDEEGA


#include<bits/stdc++.h>
using namespace std;


//HEAPIFY ALGOOOO   O(n )time complexity mei heap build 


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

int main(){
    int arr[6]= {-1, 54,53 ,55 ,52 ,50};
    int n=5;
    for(int i=n/2 ; i>0 ;i--){                // sirf first n/2 nodes process kareeengiii  kyukiii bakki ki leaf nodes hai jo already heap haii so sirf shuruaat walliiyoo ko heapify krnna
    heapify(arr, n , i);                      //0 based indexing mei size/2 -1 se i>=0 takkk
    }

    
    cout<<"printing the array now "<<endl;
    for(int i=1 ;i<= n;i++){
        cout<<arr[i]<< " ";
    }cout<<endl;

    return 0;
}