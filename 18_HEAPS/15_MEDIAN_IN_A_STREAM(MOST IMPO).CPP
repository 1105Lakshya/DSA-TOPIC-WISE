/*

Given that integers are read from a data stream. Your task is to find the median of the elements read so far.
Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.
For Example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.


Input Format:
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 

Then the T test cases follow.
The first line of each test case contains the number of elements, N, in the input data stream.

The second line of each test case contains N space separated elements of the input data stream.
Output Format:
For each test case, print the median of the elements after each incoming element. Each median value is separated by a single space.

The output of each test case is printed in a separate line.
Note :
You do not need to print anything, just return the vector of medians after each element is read from the stream. 
Constraints :
1 <= T <= 10
1 <= N <= 10^4
0 <= data <= 10^8
Where T is the number of test cases, N is the number of elements in the data stream.

Time Limit : 1 sec
Sample Input 1:
3
3
1 2 3 
2
9 9 
1
4 
Sample Output 1:
1 1 2
9 9 
4 
Explanation For Sample Input 1:
For test case 1 
After reading first element of stream , Median of [1] is 1 
After reading second element of stream, Median of [1, 2]  = floor((1+2)/2)  = 1
After reading third element of stream, Median of [1,2,3] = 2
So the output will be 1 1 2.
Sample Input 2:
2
3
5 3 8
2
3 8
Sample Output 2:
5 4 5
3 5
Explanation For Sample Input 2:
For test case 1 
After reading first element of stream, Median of [5] is 5
After reading second element of stream, Median of [5, 3]  = floor((5+3)/2)  = 4
After reading third element of stream, Median of [5,3,8] = 5 , it is the middle value of the sorted array
So the output will be 5 4 5.

*/


//approach 1 in photo
/*
we will use inserrtion sort for inserting the coming element and that will be in order of n 
for n elements SO

approach 1 time complexity is of order of sqar(n)

*/


//approach 2 
/*
we will divide the existing array into two parts  the left part will be the max heap since median ke left mei sarre elements
us se choote hotee hai and for finding the median we will be requiring the max element among them so that will be heap
ka top similarly right mei median ke saree elements us se choote hongee so we will create a min heap becoz for finding 
median we will be requiring the smallest element to the right of the median and that we can get from the top of min heap



*/




#include<bits/stdc++.h>
using namespace std;



//SOLUTION


int signum(int a, int b){
    if(a>b){
        return 1;
    }
    if(a<b){
        return -1;
    }
    return 0;
}
void callMedian(int element,vector<int> &arr ,priority_queue<int> &maxi,priority_queue<int , vector<int> ,greater<int>> &mini,int &median){
    switch(signum(maxi.size() ,mini.size())){
        case 0:if(element> median){          // dono heaps ka size equal haii toh element agar badda hogga toh agge yani min heap mei 
            mini.push(element);             //insert krdengge nahii toh max heap mei insert krdeengee
            median=mini.top();
        }
        else{
            maxi.push(element);
            median=maxi.top();
        }
        break;
        
        case 1:if(element > median){
                mini.push(element);
                median=(mini.top()+maxi.top())/2;
        }
        else{
            mini.push(maxi.top());  //is case mei direct left mei insert nahi kr sakte kyuki fir left or right part ke beech mei size diff>1 ho jaatta
            maxi.pop();           //toh iske liyee humne left se ek element uthhayaa top walla  usse right mei dallaa
            maxi.push(element);      //or fir humara jo element ayyya uskko insert krdiiyya left portion meeiii
            median =(mini.top() + maxi.top())/2;
        }
        break;
        
        case -1: if(element > median){
            maxi.push(mini.top());
            mini.pop();
            mini.push(element);
            median =(mini.top() + maxi.top())/2;
        }
        else{
            maxi.push(element);
            median =(mini.top() + maxi.top())/2;
        }
        break;
        
    }
           
           
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int , vector<int> ,greater<int>> minHeap;
    int median=-1;
    for(int i=0 ;i< n ;i++){
        callMedian(arr[i], arr, maxHeap,minHeap, median);
        ans.push_back(median);
    }
    return ans;
}













int main(){
    
    return 0;
}