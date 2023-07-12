/*
Problem Statement
You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range.
For example :
If we have 3 lists as [1, 10, 11], [2, 3, 20], [5, 6, 12] then the [1, 5] is the range that includes 1 from the first list, 2,3 from the second list, and 5 from the third list i.e, this range contains at least one element from each list.
Input Format :
The first line of the input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains two space-separated positive integers ‘N’ and ‘K’ denoting the number of the elements present in each list and the number of the lists respectively.

In the next ‘K’ lines of each test case, the ith line contains ‘N’ space-separated integers denoting the elements of the ith list.
Output Format :
For every test case, print a positive integer denoting the minimum length of the range.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= 'T' <= 50
1 <= 'N' <= 10 ^ 4  
1 <= 'K' <= 10 ^ 4  
1 <= 'N' * 'K' <= 10 ^ 4
1 <= 'VAL' <= 10 ^ 9

Where 'VAL' is the value of any element of any list.

Time Limit: 1 sec
Sample Input 1 :
2
3 2
2 4 5
5 6 7
2 3
1 1
9 12
4 9
Sample Output 1 :
1
9
Explanation For Sample Input 1 :
Test case 1 :
The given list are [2, 4, 5], [5, 6, 7]. The range [5, 5] will include 5 which is present in both the list and hence the length of this range is 1. This is the only possible range having the minimum length.

Test case 2 :
The given list are [1, 1], [9, 12], [4, 9]. The range [1, 9] will include 1 which is present in the first list, and 9 which include in both the second and third list  The length of the range is 9 (9 - 1 + 1 = 9).
Sample Input 2 :
2
3 3
4 7 30
1 2 12
20 40 50
5 1
3 6 8 12 31
Sample Output 2 :
14
1
Explanation For Sample Input 2 :
Test case 1 :
The given list are [4, 7, 30], [1, 2, 12] and [20, 40, 50]. The range [7, 20], hence the length of this range is 14. This is the only possible range having the minimum length.

Test case 2 :
The range [3, 3] will include 3 which is present in the first list. The length of the range is 1. Infect, we can select any of element present in first list as there is only one list given to us.


*/
//QUESTION KA SAAAR
/*
humme k sorted array list di hoggii humme smallest range battanii hai such that uss range mei har list kam s kam ek banda toh aa hi jayye
*/


//ALGO
/*
1-> sabse pehle humnee sarrii given sorted arrays ke starting element ka min and max nikkal liyyaaaa (min nikal ne ke liye heap)
ab max toh or neechee aaa ni sakktaa toh min ko increase krnna haii for minimum range so we will increase the min by moving to the 
next element in the array that contains minimum element  fir new range nikal lengee agar chooti huii toh update krdeenge nahhi toh 
above procedure repeat jab tak koi ek ke end mei na pahuch jaoo kisi bhi arrya ke

*/


//TIME COMPLEXITY : N*K*log(k)
//SPACE COMPLEXITY: K

/*
#include<limits.h>
#include<queue>
class node{
    public:
    int data;
    int row;
    int col;
    node(int d,int r, int c){
        this->data=d;
        this->row=r;
        this->col=c;
    }
};

class compare{
    public:
    bool operator()(node *a ,node *b){
        return a->data > b->data;
    }
};


int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini=INT_MAX;
    int maxi=INT_MIN;
    priority_queue<node* , vector<node*> ,compare>  minHeap;

    //creating a minHeap for starting elements of the lists and getting max and min for range
        
    for(int i=0 ;i< k;i++){
        int element=a[i][0];
        mini=min(mini,element);
        maxi= max(maxi ,element);
        minHeap.push(new node(element ,i ,0));  //heap mei push kareenge node row and column
    }
    
    int start=mini ,end =maxi;
    while(!minHeap.empty()){
        node* temp=minHeap.top();
        minHeap.pop();
        
        mini=temp->data;
        // agar range jo hai wo less hai toh start or end ko update krdiiya
        if(maxi - mini  < end - start){
            start=mini;
            end=maxi;
        }
        
        //check kiyya ki kya jis list ka minimum element nikalla hai uska agla element exist krta haiii agar krta hai toh max ko update krdiyyyaa or heap mei push krdiyya new minimum element
        if(temp->col +1< n){
            maxi =max(maxi , a[temp->row][temp->col +1]);
            minHeap.push(new node(a[temp->row][temp->col+1] ,temp->row ,temp->col+1));
        }
        else

        //next element does not exist
            break;
        
    }
    return end- start+1;
}

*/