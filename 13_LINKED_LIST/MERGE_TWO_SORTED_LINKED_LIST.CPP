#include<bits/stdc++.h>
using namespace std;

//*************************INTITUTION************************
//Dusri walli list mei se element uthhha rrahhee haii check kar rahee haii ki pehli walli listt mei 
// wo  kahha pe arrra  haii or uskoo whahhh daal de rahhee haiiii



/*
Node<int>* solve( Node<int>* first, Node<int>* second){
	Node<int>* curr1=first;
	Node<int>* next1=curr1 -> next;
	Node<int>* curr2=second;
	Node<int>* next2;
	while(next1 !=NULL && curr2 != NULL ){
		if((curr2-> data >= curr1->data) && (curr2-> data <= next1->data)){
				curr1-> next=curr2;
				next2=curr2->next;
				curr2->next=next1;
				curr1=curr2;
				next1=curr1->next;
				curr2=next2;
			}
		
		else{
			//curr1 and next1 ko agge bhaddadiyyaa
			curr1=next1;
			next1=curr1-> next;
			if(next1 ==NULL){ //pehli linked list khatamm toh pehli ko bacchi hui ke peeche lagga diya
				curr1-> next=curr2;  
				return first;
			}
		}
	}
	return first;
}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{	
	if(first==NULL){
		return second;
	}
	if(second==NULL){
		return first;
	}
	
	if(first->data<=second->data){
		if(first->next==NULL){
			first-> next= second;
			return first;
		}
		else
		return  solve(first,second);
	}
	else{
		if(second->next==NULL){
			second-> next= first;
			return second;
		}
		else
		return solve(second,first);
	}
}
*/



// recursive approach VERY IMPORTANT VERY TAGDI APPROACH

/*
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
    merged->next = NULL;
    return merged;
}

*/
int main(){
    
    return 0;
}