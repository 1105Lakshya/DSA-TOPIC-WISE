// *************************************************MAXIMUM KO MINIMUM KARNAAA*********************************************************************
// ********************************************************QUESTION******************************************************************

// Problem Statement
// Given an array ‘arr’ of integer numbers . where ‘arr[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students and the task is to allocate all the books to their students. Allocate books in such a way that:
// 1. Each student gets at least one book.
// 2. Each book should be allocated to a student.
// 3. Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
// Example:
// Let’s consider ‘n=4’ (number of books ) and ‘m=2’ (number of students).
// ‘arr = { 10, 20, 30, 40 }’.

// All possible way to allocate the ‘4’ books in ‘2’ number of students is -
// 10 | 20, 30, 40 - sum of all the pages of books which allocated to student-1 is ‘10’, and student-2 is ‘20+ 30+ 40 = 90’ so maximum is ‘max(10, 90)= 90’.
// 10, 20 | 30, 40 - sum of all the pages of books which allocated to student-1 is ‘10+ 20 = 30’, and student-2 is ‘30+ 40 = 70’ so maximum is ‘max(30, 70)= 70’.
// 10, 20, 30 | 40 - sum of all the pages of books which allocated to student-1 is ‘10+ 20 +30 = 60’, and student-2 is ‘40’ so maximum is ‘max(60, 40)= 60’.
// So possible maximum number of pages which allocated to a single student is { 90, 70, 60 }.
// But you have to return a minimum of this so return ‘min(90,70,60) =60’.
// Note:
// 1. Do not print anything, just return the maximum number of pages that are assigned to a student is minimum.
// 2. If it is not possible to assign the ‘n’ books to ‘m’ students then return ‘-1’.
// Input Format:
// The first line of input contains an integer ‘T’ denoting the number of test cases.
// The next ‘2*T’ lines represent the ‘T’ test cases.

// The first line of each test case contains two space-separated integers ‘n’ denoting the number of books and ‘m’ denotes the number of students. 

// The second line of each test case contains ‘n’ space-separated integers denoting the number of pages in each of ‘n’ books.
// Output Format
// For each test case, return the minimum number of pages.
// Constraints:
// 1 <= T <= 50
// 2 <= M <= N <= 10^3
// 1 <= A[i] <= 10^9
// Sum of all A[i] do not more than 10^9.


// Where ‘T’ is the total number of test cases, ‘N’ denotes the number of books and ‘M’ denotes the number of students. ‘A[i]’ denotes an element at position ‘i’ in the sequence.


// Time limit: 1 second
// Sample Input 1:
// 2
// 4 2
// 12 34 67 90
// 4 4
// 5 17 100 11
// Sample Output 1:
// 113
// 100
// Explanation Of Sample Input 1:
// Test Case 1:

// Let’s consider ‘n=4’ (number of books ) and ‘m=2’ (number of students)
// ‘arr = { 12, 34, 67, 90 }’. And ‘m= 2’.
// All possible way to allocate the ‘4’ books in ‘2’ number of students is-

// 12 | 34, 67, 90 - sum of all the pages of books which allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’ so maximum is ‘max(12, 191)= 191’.
// 12, 34 | 67, 90 - sum of all the pages of books which allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’ so maximum is ‘max(46, 157)= 157’.
// 12, 34, 67 | 90 - sum of all the pages of books which allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’ so maximum is ‘max(113, 90)= 113’.

// So possible maximum number of pages which allocated to a single student is { 191, 157, 113 } 
// But you have to return a minimum of this so return ‘min(191,157, 113) =113’.

// Hence answer is ‘113’.

// Test Case 2:

// ‘arr = { 5, 17, 100, 11 }’. And ‘m=4’.
// Only one is possible to allocate the ‘4’ books in ‘4’ student is 

// 5 | 17 | 100 | 11 - maximum is ‘max(5, 17, 100, 11)= 100’.

// Hence answer is ‘100’.
// Sample Input 2:
// 2
// 5 4
// 25 46 28 49 24
// 3 2
// 10 10 20
// Sample Output 2:
// 71
// 2



// ***********************SOLUTION***********************************************************
#include<bits/stdc++.h> 
using namespace std;

#include <bits/stdc++.h> 

 

bool isPossible(int n, int m, vector<int> time, long long int mid){

    long long int numberfDays= 1;

    long long int numberOfChapter= 0;

 

    for(int i=0; i<m; i++){

 

        if(numberOfChapter+ time[i]<=mid){

            numberOfChapter+=time[i];

        }

 

        else{

            numberfDays++;
 
            if(numberfDays>n || time[i]>mid){

                return false;

            }

            numberOfChapter= time[i];

        }

    }

    return true;

 

}

 

long long ayushGivesNinjatest(int n, int m, vector<int> time) 

{   

    long long int s=0;

    long long int sum=0;

    for(long long int num: time){

        sum+=num; 

    }

    long long int e= sum;

    long long int ans=-1;

    // Write your code here.

 

        if(n>m){

            return ans;

        }

 

    while(s<=e){

        long long int mid= s+(e-s)/2;

 

        if(isPossible( n,  m, time, mid)){

            ans=mid;

            e= mid-1;

        }

        else{

            s = mid+1;

        }

    }

 

return ans;

}

int main(){
	
	return 0;
}