//      APPROACH 1 COUNT O , 1, 2 


/*
Node* sortList(Node *head)
{
int arr[3]={0};
	Node* tem=head;
	while(tem!=NULL){
		arr[tem->data]++;
		tem=tem->next;
	}
	Node* temp=head;
	while(arr[0]){
		temp->data=0;
		temp=temp->next;
		arr[0]--;
	}
		while(arr[1]){
		temp->data=1;
		temp=temp->next;
		arr[1]--;
	}
		while(arr[2]){
		temp->data=2;
		temp=temp->next;
		arr[2]--;
	}
	return head;
}
*/

//***************************************APPROACH TWO TEEN LINKED LIST BANNA LI ZERO ONE AND TWO KI  OR FIR MERGE************************************************




/*
void insertAtTail( Node* &tail,Node* curr){
	tail-> next=curr;
	tail=curr;
}


Node* sortList(Node *head)
{
	Node* zerohead= new Node(-1);
	Node* zerotail= zerohead;
	
	Node* onehead= new Node(-1);
	Node* onetail=onehead;
	
	Node* twohead= new Node(-1);
	Node* twotail = twohead;
	
	Node* curr=head;
	//create seprate list off 0 1 2 
	while( curr != NULL ){
		int value=curr->data;
		if(value ==0){
			insertAtTail(zerotail,curr);
		}
		else	if(value ==1){
			insertAtTail(onetail,curr);
		}
		else	if(value ==2){
			insertAtTail(twotail,curr);
		}
		
		curr=curr->next;
	}
	
	
// 	Merge kardooo list koooo
	if(onehead->next!=NULL){  //matalab one wallii list empty nahi
  	zerotail->next=onehead->next; 
	}   
	else      // one wali  list jo hai wo empty haii
	{
		zerotail->next=twohead->next;
	}
	twotail->next=NULL;
	onetail->next=twohead->next;
	delete onehead;
	delete twohead;
	head=zerohead->next;
	delete zerohead;
	return head;

}
*/