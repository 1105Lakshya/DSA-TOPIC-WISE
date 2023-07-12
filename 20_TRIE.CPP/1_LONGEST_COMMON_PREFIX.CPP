/*

You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these strings. If there is no common prefix, you have to return an empty string.
A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.
For Example:
Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.
Input Format:
The first line of the input contains a single integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer ‘N’ denoting the number of strings in the array.

The next line contains ‘N’ space-separated strings denoting the elements of the array ‘ARR’.
Output Format:
For each test case, print a single string corresponding to the longest common prefix.

Print the output of each test case in a separate line.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 3000
1 <= |ARR[i]| <=1000

Each string consists of only lowercase letters.

Time limit: 1 sec
Sample Input 1:
2
4
coding codezen codingninja coder
3
night ninja nil 
Sample Output 1:
cod
ni
Explanation Of Sample Input 1:
For the first test case, 
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.

For the second test case,
The longest common prefix among all the given strings is “ni” as it is present as a prefix in all strings. Hence, the answer is “ni”.
Sample Input 2:
2
3
applejuice applepie apple
4
car cus cart carat
Sample Output 2:
apple
c

*/













//Approach
/*
Pehlii string mei left to right travel krna shurru kiyya or sarii strings se compare krte rahe
*/



//SOLUTION ONE
/*
string longestCommonPrefix(vector<string> &arr, int n)
{   //for traversing all characters of first string
    string ans="";
    for(int i=0; i<arr[0].length(); i++){
        char ch= arr[0][i];
        
        bool match =true;
        
        //for comparing character with rest of the string
        for(int j=1 ;j<n;j++){
            
            //not match
            if(arr[j].size() <= i || arr[j][i]!=ch){
                match =false;
                break;
            }
        }
        if(match==false)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}




*/





//APPROACH 2
// Using trie
/*

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
    
    
    TrieNode(char c){
        data=c;
        for(int i=0; i< 26 ;i++){
            children[i]=NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};


class Trie{
    public:
    TrieNode* root ;
    Trie(char ch){
        root=new TrieNode(ch);
    }
    
    
    //INSERTION
    void insertUtil(TrieNode* root ,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        //assumption word will be in caps
        int index=word[0]-'a';       
        TrieNode* child;


        //present
        if(root->children[index] != NULL){
            child=root->children[index];

        }
        else{
            //absent
            child= new TrieNode(word[0]);
            root->children[index]=child;
            root->childCount++;
        }

        //Recursion sambhaal legaa
        insertUtil(child, word.substr(1));    //word ka agge walla hissa bhjediyaa
    }

    void insertWord(string word){
        insertUtil(root ,word);
    }
    
    
    
    //function to calculate lcp
    void lcp(string str ,string &ans){
        for(int i=0 ;i< str.length() ;i++){
            char ch=str[i];
            if(root->childCount ==1){
                ans.push_back(ch);
                //aage bhad jaaoo
                int index =ch-'a';
                root =root ->children[index];
                    
            }
            else{
                break;
            }
            
            if(root->isTerminal == true)
                break;
        }
    }
    
    
};





string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t =new Trie('\0');
    //insert all strings into trie
    for(int i=0 ;i< n;i++){
        t->insertWord(arr[i]);
    }
    
    string first =arr[0];
    string ans="";
    
    t->lcp(first ,ans);
    return ans;
}





*/