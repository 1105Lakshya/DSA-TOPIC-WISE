/*
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
*/





//ALGO
/*
merge the two arrayss and then heapifyyy 
*/



/*

class Solution{
    private:
    void heapify(vector<int>& arr, int n, int i){             // n is the size of heap
    int largest = i;             // i is the index for and below which we have to convert the tree into min heap
    int left = 2*i+1;
    int right =2*i+2;

    if(left<n &&  arr[largest ]< arr[left]){            // checking if child lies within range and comparing value with child
    largest=left;
    }
    if(right < n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest != i ){           // checking if  largest is updated or not 
    swap(arr[largest] , arr[i]);     //if updated then we have to swap the values for converting the tree into heap
    heapify(arr , n , largest );        // humnee kahha neeche wallle bacche huue tree mei bhii  jo swap honne ke baad value pahuchi hai usko sahi jagga pahucha doo toh recursive call
    }

}
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //step 1 ----> mergge arrays
    vector<int> c;
    for(int i=0;i<n ;i++){
        c.push_back(a[i]);
    }
    for(int i=0 ;i< m ;i++){
        c.push_back(b[i]);
    }
    
    
    
    
    //step 2 -----> build heap using merged array

    int size=c.size();
    for(int i=size/2 -1 ; i>=0 ;i--){              //0 basedd indexing mei size/2 -1 se i>=0   carefull
        heapify(c, size ,i);
    }
    
    return c;
    }
};



*/