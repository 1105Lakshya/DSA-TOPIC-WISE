#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];           //an array of TrieNode pointers
    bool isTerminal;

    TrieNode(char ch){
        data= ch;
        for(int i =0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};


class Trie{
    private:
    TrieNode* root;                     //root node banna di trie kiiii
    public:

    Trie(){                                    //first(root node) ko null se assign krdiyya
        root = new TrieNode('\0');
    }





//INSERTION
    void insertUtil(TrieNode* root ,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        //assumption word will be in caps
        int index=word[0]-'A';       
        TrieNode* child;


        //present
        if(root->children[index] != NULL){
            child=root->children[index];

        }
        else{
            //absent
            child= new TrieNode(word[0]);
            root->children[index]=child;
        }

        //Recursion sambhaal legaa
        insertUtil(child, word.substr(1));    //word ka agge walla hissa bhjediyaa
    }

    void insertWord(string word){
        insertUtil(root ,word);
    }




//SEARCHING
bool searchUtil(TrieNode* root ,string word){
    //base case 
    if(word.length() == 0){
        return root->isTerminal;
    }

    int index =word[0] -'A';
    TrieNode* child;

//present
    if(root->children[index] != NULL){
        child=root->children[index];
}
else{
    return false;
}
//recursion
return searchUtil(child ,word.substr(1));

return false;

}



bool searchWord(string word){
    return searchUtil(root ,word);
}







//DELETION
// search for a word if it is present last wallliii node ka isTerminal false karrdooo
void deleteUtil(TrieNode* root ,string word){
    //base case 
    if(word.length() == 0){
         root->isTerminal =false;
         return ;
    }

    int index =word[0] -'A';
    TrieNode* child;

//present
    if(root->children[index] != NULL){
        child=root->children[index];
}
else{
    return ;
}
//recursion
deleteUtil(child ,word.substr(1));


}



void deleteWord( string word){
    deleteUtil(root ,word);
}










};


class Node{
    public:
        char data;
        Node* next[26];
        bool isterminal;

        Node(char ch){
            data=ch;
            for(int i=0 ;i<26;i++){
                next[i]=NULL;
            }
            isterminal=false;
        }
};






class TrieLeetcode {

    Node* root;

public:
    TrieLeetcode() {
        root=new Node('@');
    }
    
    void insert(string word) {
        int len=word.length();
        if(len==0){
        root->isterminal=true;
        return ;            
        }

        Node* tail=root;

        for(int i=0 ;i< len;i++){
            int index=word[i]-'a';

            if(tail->next[index]!=NULL){
                tail=tail->next[index];
            }
            else{
                tail->next[index]=new Node(word[i]);
                tail=tail->next[index];
            }
        }
        tail->isterminal=true;
    }
    




    bool search(string word) {
        int len=word.length();
        if(len==0)return root->isterminal;

        Node* tail=root;
        for(int i=0 ;i<len;i++){
            int index=word[i]-'a';
            if(tail->next[index]!=NULL){
                tail=tail->next[index];
            }
            else{
                return false;
            }
        }
        return tail->isterminal;
    }




    
    bool startsWith(string word) {
        int len=word.length();
        if(len==0)return true;

        Node* tail=root;
        for(int i=0 ;i<len;i++){
            int index=word[i]-'a';
            if(tail->next[index]!=NULL){
                tail=tail->next[index];
            }
            else{
                return false;
            }
        }

        return true;
        
    }
};






















int main(){
    Trie *t =new Trie();
    t->insertWord("DEEPIKAISLOVE");
    t->insertWord("DEEPIKAISLIFE");
    t->insertWord("DEEPIKAISJAAN");
    if(t->searchWord("DEEPIKAISJAAN"))
    cout<<"I LOVE YOU DEEPIKA" <<endl;
    else{
        cout<<"INTEQUAAMM DEKHEEEGI"<<endl;
    }
    t->deleteWord("DEEPIKAISJAAN");
    if(t->searchWord("DEEPIKAISJAAN"))
    cout<<"I LOVE YOU DEEPIKA" <<endl;
    else{
        cout<<"INTEQUAAMM DEKHEEEGI"<<endl;
    }
    
    
    return 0;
}