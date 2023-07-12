#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};






//INSERTION KI TIME COMPLEXITY LOG(n) IN CASE OF A BINARY TREE


Node*  insertIntoBST(Node* root ,int  data){
//base case 
if(root==NULL){
root=new Node(data);
return root;
}

if(data>root->data){
    //right part mei insert karnna haiii
    root->right =insertIntoBST(root->right,data);
}
else{
    //left part mei insert karnaa hai
    root->left=insertIntoBST(root->left , data);
}


return root;
}


void takeInput(Node* & root ){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root, data);
        cin>>data;
    }
}


//***********************************LEVEL ORDER TRAVERSAL*************************

void levelOrderTraversal(Node* root){
    queue<Node*>  q;
    q.push(root);           
    q.push(NULL);  //pehlii Node ke liyee seprator daal diyyyaaa       

    // NULL separate karregaaa q meii different levels koooo

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp==NULL){   //puranna level complete traverse ho chukkaa haiii
        cout<<endl;               // tohh enter maardiyyyaa
        if(!q.empty()){      //queue still has some child Nodes 
        q.push(NULL);           //is samaya next level ke sarre present honngge q meii  toh  NULL daal diyya q ke end mei  to separate from the ones that will be entered 

        }
        }
        else{
        cout<<temp->data<<" ";      // agar null ni haii toh jo agge padda q meii uskaa data print kardooo
        if(temp->left  != NULL){
        q.push(temp->left);
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }

        }

    }
}




/***************************DELETION IN BINARY TREE*********************************************/

int minivalue(Node* root){
    Node* temp=root;
    while(temp->left !=NULL)
    temp=temp->left;


    return temp->data;
}






Node* deleteFromBST(Node* root , int val){
    //base case
    if(root==NULL)
    return root;

    if(root->data==val){
        //if 0 child
        if(root->left ==NULL  && root->right==NULL){
            delete root;
            return NULL;
        }

        // if 1 child
        if(root->left !=NULL  && root ->right ==NULL  ){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->right !=NULL  && root ->left ==NULL  ){
            Node* temp=root->right;
            delete root;
            return temp;
        }


        //if 2 child                     //is case mei left se max value nikkal ke laaoo or usse present root ka data banna do or fir usse delte karrdo
        if(root->left !=NULL && root->right!=NULL) {                            // or right se minimum value nikkal ke leaoo or uppar walla procedure repeat
        int minimum_ =minivalue(root->right);
        root->data=minimum_;
        root->right =deleteFromBST(root->right , minimum_);
        return root;

    }

    else if(root->data > val){
        //left part mei jaaaoooo
        root->left=deleteFromBST(root->left, val);
        return root ;

    }
    else{

        //right part mei jaaoo
        root->right=deleteFromBST(root->right, val);
        return root ;

    }
}
}












int main(){
    Node* root=NULL;
    cout<<"My lovely deepika data enter karrooo  BST mei enter krnne ke liyyee "<<endl;
    takeInput(root);
    

    cout<<"deepika mella bachha mai BST print karra huu "<<endl;

    levelOrderTraversal(root);
    return 0;
}