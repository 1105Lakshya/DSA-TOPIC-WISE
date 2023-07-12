/*

Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

                                               

Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts root node of the tree as parameter and returns the maximum sum as described.

Expected Time Complexity: O(Number of nodes in the tree).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000




'

*/






//SOLUTION


/*
class Solution{
    //we will make pair of integer that will contain the sum if that particular node is included and if that particular node is excluded
    // make_pair( included_sum , excluded_sum)
  private:
  pair<int,int> solve(Node*root ){
      //base case
      if(root ==NULL)
      return make_pair(0,0);
      
      pair<int ,int > leftsum;
      leftsum=solve(root->left);
      pair<int ,int > rightsum;
      rightsum=solve(root->right);

      int included_sum=root->data+leftsum.second+rightsum.second;  // if node is included then we cannot take leftnode and right node of that particular node so we have to sum the data of that node and data of sum excluding below two nodes


      int excluded_sum=max(leftsum.first,leftsum.second) +max (rightsum.first,rightsum.second);    // if we exclude that node we can include left node as well as exclude so we will use the case that will give us maximum summm
      
      return make_pair(included_sum,excluded_sum);
      
      
      
  }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int,int > ans;
        ans=solve(root);
        return max(ans.first,ans.second);
    }
};










*/