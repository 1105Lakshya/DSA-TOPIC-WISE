/*
373. Find K Pairs with Smallest Sums
Medium
5.3K
308
Companies
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in ascending order.
1 <= k <= 104



*/

/*


Approach: Using Heap
Intuition
The brute force approach to solving this problem is to compute the sum of all the pairs, sort the list of sums, and select the first 'k' elements from it. If the size of nums1 is m and size of nums2 is n, there will be m * n pairs in total that will be formed. As a result, it will take O(m⋅n)O(m \cdot n)O(m⋅n) time to calculate the sum of all the pairs and O(m⋅n⋅log⁡(m⋅n))O(m \cdot n \cdot \log(m \cdot n))O(m⋅n⋅log(m⋅n)) time to sort the list of sums. This will result in the time limit being exceeded (TLE).

We can see from the problem description that both arrays are sorted. Let us try to make use of it.

Because the arrays are sorted, the pair with the smallest sum is undoubtedly the one formed by selecting the first element from both arrays, i.e., pair with indices (0, 0) where the first element is index of nums1 and second is index of nums2. As a result, we add (nums1[0], nums2[0]) to our answer list.

What about the next pair whose sum is just greater than (or equal to) the sum of the previous pair?

The next pair with a sum that is just greater than (or equal to) the sum of the previous pair would be formed by selecting either the first element of nums1 and the second element of nums2, (0, 1), or the second element of nums1 and the first element of nums2, (1, 0), whichever has smaller sum. We only need to look at these two pairs because the sum of all the other pairs will be greater than this pair.

Assume we chose (0, 1) as our second pair. The next smallest pair whose sum is greater than (or equal to) the sum of the second pair is either the previous iteration's leftover pair (1, 0), or one of the pairs formed by taking the current pair (0, 1) and taking a new element from either array, so either (1, 1) or (0, 2) (notice that this is the same option we had after taking the first pair (0, 0)).

At each step, we chose the minimum sum pair from the remaining leftover pairs and the next two new pairs. The answer will not be present outside of these pairs being considered only because the arrays are sorted. We repeat this process until we get k pairs.

A heap is a useful data structure when it is necessary to repeatedly remove the object with the lowest (or highest) priority, or when insertions need to be interspersed with removals of the objects.

We will use a min heap to solve the problem because we need to iterate from the lowest sum of a pair to pairs with higher sums. The sums of pairs will be stored in the heap, and the data structure will keep the sums in sorted order. We must store the information of the indices of nums1 and nums2 that lead to the formation of a particular sum in the heap in order to return the pair of integers.

In the heap, we would store a triplet of integers: the pair's sum, the first element's index in nums1, and the second element's index in nums2. We start with an empty list ans and push all of the k pairs that make up the answer one-by-one.

We begin by inserting nums1[0] + nums2[0], 0, 0 into the heap because the sum of the first element of both arrays is guaranteed to be the smallest.

To obtain the minimum sum of a pair among all the pairs under consideration, the top of the heap is popped out. We save the triplet in val, i and j. We put the pair (nums1[i], nums2[j]) in ans.

We then push the two new pairs as discussed in the heap. We push nums1[i + 1] + nums2[j], i + 1, j and nums1[i] + nums2[j + 1], i, j + 1.

We do this until we get k pairs or heap becomes empty which would happen if we have covered all the m * n pairs and k > m * n, where m is size of nums1 and n is size of nums2.

The only thing to keep in mind here is that when we push the new pairs, there may be repeating states. For i = 1 and j = 0, for example, we will push i = 2, j = 1 and i = 1, j = 1. If i = 1, j = 1 is popped again, we will push i = 2, j = 1 and i = 1, j = 2. The pair i = 2, j = 1 is pushed twice, as can be seen.

To avoid this, we can create a hash set called visited and store the pairs that have already been pushed into the heap in order to avoid pushing them again.

Here is a visual representation of how this approach works for the first example given in the problem description:

Current

This method is very similar to the Dijkstra algorithm in that we find the shortest distance between any two nodes. To find the edge with the smallest weight, we heap all of the edge weights. Then we move on to the next node (using minimum weight edge selected). We add all of the edge weights for the edges connected with the node back to the heap from the current node and choose the edge with the lowest weight from the available edges. We use the edge to move to another unvisited node and continue popping nodes and adding edge weights to the heap until all of the nodes are covered.

Algorithm
Create two integer variables m and n. Initialize them to size of nums1 and nums2 respectively.
Create a list ans to store the pairs with smallest sums that are to be returned as the answer.
Create a hash set visited to keep track of pairs that are seen. Please note that we used ordered_set in C++ in place of unordered_set because the unordered_set uses hash template to compute hashes for its entries and there is no hash specialization for pairs. Either we define the hash function of pairs or use ordered_set which is a little expensive as it adds log factor. We are using ordered_set here.
Initialize a min heap minHeap that takes a triplet of integers: the sum of the pair, the index in nums1 of the first element of the pair, and the index in nums2 of the second element of the pair.
Push the first element from the both the arrays in minHeap, i.e., we push nums1[0] + nums2[0], 0, 0. We also insert pair (0, 0) in visited.
Iterate till we get k pairs and minHeap is not empty:
Pop the top of minHeap and set i = top[1] and j = top[2].
Push pair (nums1[i], nums2[j]) in ans.
If i + 1 < m and pair (i + 1, j) is not in visited, we push a new pair nums1[i + 1] + nums2[j], i + 1, j into the heap.
If j + 1 < n and pair (i, j + 1) is not in visited, we push a new pair nums1[i] + nums2[j + 1], i, j + 1 into the heap.
Return ans.
Implementation

Complexity Analysis
Here, mmm is the size of nums1 and nnn is the size of nums2.

Time complexity: O(min⁡(k⋅log⁡k,m⋅n⋅log⁡(m⋅n)))O(\min(k \cdot \log k, m \cdot n \cdot \log (m \cdot n)))O(min(k⋅logk,m⋅n⋅log(m⋅n)))

We iterate O(min⁡(k,m⋅n))O(\min(k, m \cdot n))O(min(k,m⋅n)) times to get the required number of pairs.
The visited set and heap both can grow up to a size of O(min⁡(k,m⋅n))O(\min(k, m \cdot n))O(min(k,m⋅n)) because at each iteration we are inserting at most two pairs and popping one pair. Insertions into a min-heap take an additional log⁡\loglog factor. So, to insert O(min⁡(k,m⋅n))O(\min(k, m \cdot n))O(min(k,m⋅n)) elements into minHeap, we need O(min⁡(k⋅log⁡k,m⋅n⋅log⁡(m⋅n))O(\min(k \cdot \log k, m \cdot n \cdot \log (m \cdot n))O(min(k⋅logk,m⋅n⋅log(m⋅n)) time.
The visited set takes on an average constant time and hence will take O(min⁡(k,m⋅n))O(\min(k, m \cdot n))O(min(k,m⋅n)) time in major languages like Java and Python except in C++ where it would also take O(min⁡(k⋅log⁡k,m⋅n⋅log⁡(m⋅n)))O(\min(k \cdot \log k, m \cdot n \cdot \log (m \cdot n)))O(min(k⋅logk,m⋅n⋅log(m⋅n))) because we used ordered_set that keeps the values in sorted order.
Space complexity: O(min⁡(k,m⋅n))O(\min(k, m \cdot n))O(min(k,m⋅n))

The visited set and heap can both grow up to a size of O(min⁡(k,m⋅n))O(\min(k, m \cdot n))O(min(k,m⋅n)) because at each iteration we are inserting at most two pairs and popping one pair.




*/


#include<bits/stdc++.h>
using namespace std;





int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}