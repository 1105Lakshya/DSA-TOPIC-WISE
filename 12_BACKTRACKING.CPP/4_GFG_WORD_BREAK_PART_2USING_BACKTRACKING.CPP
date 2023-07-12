/*
Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

Follow examples for better understanding.

Example 1:

Input: s = "catsanddog", n = 5 
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
Explanation: All the words in the given 
sentences are present in the dictionary.
Example 2:

Input: s = "catsandog", n = 5
dict = {"cats", "cat", "and", "sand", "dog"}
Output: Empty
Explanation: There is no possible breaking 
of the string s where all the words are present 
in dict.
*/




/*

class Solution{
private:
void    solve(string str ,int index , unordered_set<string> &set, vector<string> &ans){
    //base case
    if(index>=str.size()){
        ans.push_back(str);
    }
    string temp="";
    while(index<str.size() ){
        temp=temp+str[index++];
        if(set.find(temp)!=set.end()){
            if(index<str.size())
            str.insert(index," ");
            solve(str ,index+1, set ,ans);
            str.erase(index ,1);
            
        }
        
        
        
    }

        
    }
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans;
        unordered_set<string > set;
        for(auto it : dict){
            set.insert(it);
        }
        solve(s, 0 ,set ,ans);
        return ans;
    }
};



*/