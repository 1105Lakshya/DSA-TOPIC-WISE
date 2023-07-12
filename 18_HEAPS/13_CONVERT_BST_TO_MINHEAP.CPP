//convert a binary search tree to min heap such that the left part have less value than right part for all nodes
//bst is a complete tree

// ALGO

/*
get inorder traversal array of BST

now for min heap   node->data  < left ->data         &&  node->data < right ->data
plus   left->data   < right ->data         giveen in   question   means  node->data < left->data < right ->data  NLR
so final output is   populate the BST  with preorder traversal from inorder array
*/