#include <bits/stdc++.h>
using namespace std;

/* A binary tree tNode has data, a pointer to left child
and a pointer to right child */
struct tNode {
	int data;
	struct tNode* left;
	struct tNode* right;
};










/* Function to traverse the binary tree without recursion
and without stack */
void MorrisTraversal(struct tNode* root)
{
	struct tNode *current, *pred;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {

		if (current->left == NULL) {
			cout << current->data << " ";
			current = current->right;
		}
		else {

			/* Find the inorder predecessor of current */              //predecessor is ek thaapaa left mei or fir wahhha se right jab tak right mei NULL na mill jayyyye
			pred = current->left;
			while (pred->right != NULL
				&& pred->right != current)
				pred = pred->right;

			/* Make current as the right child of its
			inorder predecessor */
			if (pred->right == NULL) {
				pred->right = current;
				current = current->left;
			}

			/* Revert the changes made in the 'if' part to
			restore the original tree i.e., fix the right
			child of predecessor */
			else {
				pred->right = NULL;
				cout << current->data << " ";
				current = current->right;
			} /* End of if condition pred->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */
}











/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
given data and NULL left and right pointers. */
struct tNode* newtNode(int data)
{
	struct tNode* node = new tNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
			1
		/ \
		2	 3
	/ \
	4	 5
*/
	struct tNode* root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	MorrisTraversal(root);

	return 0;
}

// This code is contributed by Sania Kumari Gupta (kriSania804)
