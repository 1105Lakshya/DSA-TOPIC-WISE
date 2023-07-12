/*
Given 'K' sorted linked lists, each list is sorted in increasing order. You need to merge all these lists into one single sorted list. You need to return the head of the final linked list.
Input Format:
The first line of input contains an integer 'T' denoting the number of queries or test cases. 

The first line of each test case consists of an integer 'K' denoting the number of lists.

Next 'K' lines for each test case will have space separated integers and ith line will have elements of the ith linked list separated by a single space and terminated by -1.
Output Format:
For each test case, print a single line containing space-separated denoting the elements of the merged sorted list. The elements of the linked list must be separated by a single space and terminated by -1.

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
0 <= K <= 10 ^ 3
0 <= length of lists <= 100
(-10 ^ 9) <= value of list elements <= (10 ^ 9) && value of list elements != -1.

Time limit: 1 sec.
Sample Input 1:
 2
 3
 4 6 8 -1
 2 5 7 -1
 1 9 -1
 2
 2 6 -1
 -5 7 -1
Sample Output 1:
 1 2 4 5 6 7 8 9 -1
 -5 2 6 7 -1
Explanation For Input 1:
For first test case:
First list is: 4 -> 6 -> 8 -> NULL
Second list is: 2 -> 5 -> 7 -> NULL
Third list is: 1 -> 9 -> NULL
The final list would be: 1 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL

For second test case:
First list is: 2 -> 6 -> NULL
Second list is: -5 -> 7 -> NULL
The final list would be: -5 -> 2 -> 6 -> 7 -> NULL
Sample Input 2:
 2
 3
 8 9 11 -1
 1 2 -1 
 -1 
 1
 1 5 6 8 10 -1
Sample Output 2:
1 2 8 9 11 -1
1 5 6 8 10 -1

*/



//ALGO
//SAME AS PREVIOUS QUESTION
/*




#include <queue>
//comparator for minHeap
class compare{
    public:
    bool operator()(Node<int> *a ,Node<int> *b){
        return a->data > b->data;     
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*  ,vector<Node<int>*> ,compare> minHeap;
    Node<int> *head=NULL;
    Node<int> *tail=NULL;
    int k=listArray.size();
    //step1:
    for(int i=0 ;i<k;i++){
        if(listArray[i]!= NULL){
            minHeap.push(listArray[i]);
        }
    }
    while(minHeap.size() > 0){
        Node<int> *top=minHeap.top();
        minHeap.pop();
        
        if(head==NULL){
            head=top;
            tail=top;

        }
        else{
            tail->next =top;
            tail=top;
        }
        if(tail->next !=NULL){
            minHeap.push(tail->next);
         }
    }
    
    return head;
}




*/