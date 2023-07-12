// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 


// 
//     Node*head=new Node(-1);
//     Node*temp=head;
//     while(head1 != NULL && head2 !=NULL){
    
//     if(head1->data < head2->data){
//     temp->next=head1;
//     temp=head1;
//     head1=head1->next;
//     }
//     else{
//     temp->next=head2;
//     temp=head2;
//     head2=head2->next;
//     }
//     }
//     while(head1 !=NULL){
//         temp->next=head1;
//     }
//     while(head2!=NULL){
//         temp->next=head2;
//     }
//     return head->next;
// }



// class Solution{
//   private:
//   Node *merge(Node *first, Node *second)
// {
//     // If the first is NULL return second
//     if (first == NULL)
//     {
//         return second;
//     }

//     // If the second is NULL return first
//     if (second == NULL)
//     {
//         return first;
//     }

//     Node *merged = NULL;

//     if (first->data < second->data)
//     {
//         merged = first;
//         merged->next = merge(first->next, second);
//     }
//     else
//     {
//         merged = second;
//         merged->next = merge(first, second->next);
//     }
//     merged->next = NULL;
//     return merged;
// }



//   public:
//     //Function to merge K sorted linked list.
//     Node * mergeKLists(Node *arr[], int K)
//     {   
//     //     static int count=0;
//     //     if(k==1){
//     //         return *(arr+count);
//     //     }
//     //   Node*list1=arr[count];
//     //   count++;
//     //   Node*list2=mergeKLists( ( arr+count),k-1);
//     //   Node *ans=merge(arr[count-1],list2);
//     //   return ans;
//               for(int i=0;i<K-1;i++)
//           {
//               arr[i+1] = merge(arr[i],arr[i+1]);
//           }
//           return arr[K-1];
//     }
// };

class Solution{
 public:
    Node *merge(Node *first, Node *second)
{
    // If the first is NULL return second
    if (first == NULL)
    {
        return second;
    }

    // If the second is NULL return first
    if (second == NULL)
    {
        return first;
    }

    Node *merged = NULL;

    if (first->data < second->data)
    {
        merged = first;
        merged->next = merge(first->next, second);
    }
    else
    {
        merged = second;
        merged->next = merge(first, second->next);
    }
    // merged->next = NULL;
    return merged;
}


   //Function to merge K sorted linked list.
   Node * mergeKLists(Node *arr[], int K)
   {
          // Your code here
          for(int i=0;i<K-1;i++)
          {
              arr[i+1] = merge(arr[i],arr[i+1]);
          }
          return arr[K-1];
   }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends