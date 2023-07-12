//WHAT IS HEAP?
/*Heap is a complete binary tree that comes with a heap order property .*/


//COMPLETE BINARY TREE
/*
1-> Every level is completely filled  except the last level .
2-> Nodes always added from the left  or Nodes always lean towards the left .
*/

//HEAP ORDER PROPERTY 
/*
1-> MAX HEAP                     2-> MIN HEAP

MAXHEAP----->Har Node ke child us se chhoteee hongeee matlab baap ka data badda hogaaa
MINHEAP----->Har Node ke child us se badde hongeeeeee matlab baap ka data choota hoggaa
*/


/*
1->NEXT CHILD OF A NODE IN ONE BASE INDEXING----->        left:2*i          right:2*i+1
1->NEXT CHILD OF A NODE IN ZERO BASE INDEXING----->        left:2*i +1         right:2*i+2


*/

#include<bits/stdc++.h>
using namespace std;


class heap{
    public:
    int  arr[100];
    int size;

heap(){
    arr[0]=-1;
    size=0;
}



//FUNCTION TO INSERT IN A HEAP IN ARRAY IMPLEMENTATION
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;

        while(index>1){
            int parent=index/2;

            if(arr[parent]< arr[index]){            //max heap hai na dost papa ko badda rakhhna hotaa hai toh swap kardooo 
            swap(arr[parent] ,arr[index]);
            index=parent;                            // index update kardiyaaa
            }
            else{
                return ;
            }
        }
    }







//DELETION (deleting the root node)
/*
step1---> put the ending node of the heap to the starting position.
step2---> Delte the ending position
step3---> Validate the heap and change accordingly check if the parent node is greater than its children if not swap the maximum value among
the threee with the parent node and check further till the max heap condition is satisfied.
*/
//deletion complexity : log(N) 
void deletefromheap(){
    if(size==0){
        cout<<"Heap is empty"<<endl;
        return ;
    }
    arr[1]=arr[size];              //step 1
    size--;          //setp 2

    //take root node to its correct position 
    int i=1;
    while(i< size){
        int leftIndex=2*i;
        int rightIndex=2*i +1;

        if(leftIndex < size && arr[i]<arr[leftIndex]){
            swap(arr[i] , arr[leftIndex]);
            i=leftIndex;
        }
        if(rightIndex < size && arr[i] < arr[rightIndex]){
            swap(arr[i], arr[rightIndex]);
            i=rightIndex;
        }
        else{
            return ;
        }
    }

    

}






//function to print
void print(){
    for(int i=1 ;i<=size ;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}




};

int main(){
    heap h;
    h.insert(52);
    h.insert(55);
    h.insert(53);
    h.insert(54);
    h.insert(50);

    h.print();
    
    return 0;
}