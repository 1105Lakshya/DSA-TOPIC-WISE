#include<bits/stdc++.h>
using namespace std;
// *********************************************O(N)SPACE COMPLEXITY***************************************************************
class Solution {
public:
    string reverseWords(string s) {
    string ans;
    string temp;
    for(int i=0;s[i]!='\0';i++){
        while(s[i]==' '  && s[i]!='\0')
        {
            i++;
        }
        
        while(s[i]!=' '  && s[i]!='\0'){
            temp.push_back(s[i]);
            i++;
        }
        i--;
        temp.push_back(' ');
        ans.insert(0,temp);
        temp.clear();
    }   
        int n=ans.length();
        while(ans[n-1]==' '){
        ans.pop_back();
        }
        while(ans[0]==' '){
        ans.erase(0,1);
        }
        return ans;
    }
};

// **************************************************CONSTANT EXTRAA SPACE********************************************************
class Solution {
public:

    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        } 
    }
    
    void reverseWords(string &s) {
        
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        
        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;} 
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;
            
        }
        
        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }
};

int main(){
    
    return 0;
}



////////////////////////////////////////////////////////////////////GOOD SOlUTION//////////////////////////////////////////////////////////
string reverseWords(string s) {
        if(s.size() == 0) return s;
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
            stack.push(word); //push word to the stack
        }
        while(!stack.empty()) {
            result += stack.top(); stack.pop();
            if(!stack.empty()) result += " ";
        }
        return result;
    }
};