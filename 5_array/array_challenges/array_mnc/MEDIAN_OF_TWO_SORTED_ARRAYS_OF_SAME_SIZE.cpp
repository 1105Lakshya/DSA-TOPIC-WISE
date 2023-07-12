#include<bits/stdc++.h>
using namespace std;






/*Time Complexity : O(n)

Auxiliary Space: O(1)*/
//*******************method 1 ****************************************
//akkhri ke do number rakhhtee chaloo nayyyi array jo bantiii uskkkeee or jaise ji uska count n+1 ho jayyeee return kardoo undoomoo ka sum

int median(int  arr[], int brr[], int n){
    int m1=-1;        // m1 and m2  for keeping the track of the last two elements of the array upto which we have traversed
    int m2=-1;              
    int count=0;
    int i=0;
    int j=0;
    while(count !=n+1){
         if (i == n)
        {
            m1 = m2;
            m2 = brr[0];
            break;
        }
 
        /*Below is to handle case where
          all elements of ar2[] are
          smaller than smallest(or first)
          element of ar1[]*/
        else if (j == n)
        {
            m1 = m2;
            m2 = arr[0];
            break;
        }
        if(arr[i]<brr[j]){
            m2=m1;
            m1=arr[i];
            i++;
            count++;
        }
        else{
            m2=m1;
            m1=brr[j];
            j++;
            count++;

        }
    }
return (m1+m2)/2;
}


/*************************recursive method  complexity  O(log n)*************************************/
/* to get median of a
   sorted array */
int median(int [], int);
 
/* This function returns median
   of ar1[] and ar2[].
Assumptions in this function:
    Both ar1[] and ar2[] are
    sorted arrays
    Both have n elements */
int getMedian(int ar1[],
              int ar2[], int n)
{
    /* return -1 for
       invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] +
                ar2[0]) / 2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) +
                min(ar1[1], ar2[1])) / 2;
 
    /* get the median of
       the first array */
    int m1 = median(ar1, n);
     
    /* get the median of
       the second array */
    int m2 = median(ar2, n);
 
    /* If medians are equal then
       return either m1 or m2 */
    if (m1 == m2)
        return m1;
 
    /* if m1 < m2 then median must
       exist in ar1[m1....] and
                ar2[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n / 2 - 1,
                             ar2, n - n / 2 + 1);
        return getMedian(ar1 + n / 2,
                         ar2, n - n / 2);
    }
 
    /* if m1 > m2 then median must
       exist in ar1[....m1] and
                ar2[m2...] */
    if (n % 2 == 0)
        return getMedian(ar2 + n / 2 - 1,
                         ar1, n - n / 2 + 1);
    return getMedian(ar2 + n / 2,
                     ar1, n - n / 2);
}
 
/* Function to get median
   of a sorted array */
int median(int arr[], int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] +
                arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}





int main(){
    int n;
    cin>>n;
    int arr[n];
    int brr[n];
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    for(int i=0;i<n;i++){
        cin>> brr[i];
    }
    cout<<"median of the two sorted arrays entered by u is "<<  median(arr , brr , n)<<endl;
    
    return 0;
}











// /* This function returns
// median of ar1[] and ar2[].
// Assumptions in this function:
// Both ar1[] and ar2[]
// are sorted arrays
// Both have n elements */
// int getMedian(int ar1[],
//               int ar2[], int n)
// {
//     int i = 0; /* Current index of
//                   i/p array ar1[] */
//     int j = 0; /* Current index of
//                   i/p array ar2[] */
//     int count;
//     int m1 = -1, m2 = -1;
 
//     /* Since there are 2n elements,
//     median will be average of elements
//     at index n-1 and n in the array
//     obtained after merging ar1 and ar2 */
//     for (count = 0; count <= n; count++)
//     {
//         /* Below is to handle case where
//            all elements of ar1[] are
//            smaller than smallest(or first)
//            element of ar2[]*/
//         if (i == n)
//         {
//             m1 = m2;
//             m2 = ar2[0];
//             break;
//         }
 
//         /*Below is to handle case where
//           all elements of ar2[] are
//           smaller than smallest(or first)
//           element of ar1[]*/
//         else if (j == n)
//         {
//             m1 = m2;
//             m2 = ar1[0];
//             break;
//         }
//         /* equals sign because if two
//            arrays have some common elements */
//         if (ar1[i] <= ar2[j])
//         {
//             /* Store the prev median */
//             m1 = m2;
//             m2 = ar1[i];
//             i++;
//         }
//         else
//         {
//             /* Store the prev median */
//             m1 = m2;
//             m2 = ar2[j];
//             j++;
//         }
//     }
 
//     return (m1 + m2)/2;
// }

