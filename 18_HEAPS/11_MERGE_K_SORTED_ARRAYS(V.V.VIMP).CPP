/*

You have been given ‘K’ different arrays/lists, which are sorted individually
(in ascending order). You need to merge all the given arrays/list such that the
output array/list should be sorted in ascending order.

*/





//ALGO
/*
STEP1->put the first elements of all the arrays 
STEP2-> put the minimum element from the heap 
STEP3->insert krdiiya next element agar exist krrtaa hai toohh heap mei uss array ka jiskaa element abbhiih
humnne answer meii dalllaa 


*/


/*

#include <queue>
class node{
    
    public:
    int data;
    int i;
    int j;
    node(int data, int row ,int col){
        this->data=data;
        this->i=row;
        this->j=col;
        
    }
};

class compare{
    public:
    bool operator()(node*a , node*b ){
        
        return a->data  > b->data;
    }
};


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node* ,vector<node*> ,compare> minHeap;      //humnee ek aisa minheapl bannaa liyyaa jo node ki data value ke uppar sort krtta haiii
    
    
//     step1 :sarree araays k first element insert h
    for(int i=0 ;i< k;i++){
        node* temp=new node(kArrays[i][0] , i , 0);             //element row number col number
        minHeap.push(temp);
    }
    
    vector<int> ans;
    
//     step2 :
    while(minHeap.size()> 0){
        node* temp =minHeap.top();
        
        ans.push_back(temp->data);
        minHeap.pop();
        
        int i =temp->i;
        int j=temp->j;
        
        if(j+1 < kArrays[i].size()){       // agar agla element array ke size se choota haiii
            node* next = new node(kArrays[i][j+1] , i ,j+1);
            minHeap.push(next);
            
        }
    }
    return ans;
}


*/