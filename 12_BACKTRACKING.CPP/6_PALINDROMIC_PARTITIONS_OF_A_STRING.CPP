/*

Given a String S, Find all possible Palindromic partitions of the given String.
 

Example 1:

Input:
S = "geeks"
Output:
g e e k s
g ee k s
Explanation:
All possible palindromic partitions
are printed.
Example 2:

Input:
S = "madam"
Output:
m a d a m
m ada m
madam

*/


/*
class Solution {
    
  private:
  bool isSafe(string str){
      string temp=str;
      reverse(str.begin(), str.end());
        
     if(str==temp)
     return true;
     
     
     return false;
  }
  
  
void  solve(string str ,vector<vector<string>> &ans ,vector<string> output){
    //BASE CASE                                        //AGAR SARRI STRINGS KHATAM MATLAB SARRI SAFE THIII TOH ANS MEI PUSHHH
      if(str.size()==0)
      ans.push_back(output);
      
      for(int index=0 ; index < str.size() ;index++){          // PEHLLE SIZE 1 KI CHECK KRII AGAR SAFE HAII TOH AGGE CALL MARRDI
          string temp=str.substr(0,index+1);
          if(isSafe(temp)){
              output.push_back(temp);
              string bacchii_huii=str.substr(index+1,100);
              
              //RECURSIVE CALL
              solve(bacchii_huii,ans ,output );

              //BACKTRACK
              output.pop_back();
              
          }
      }
  }
    
  public:
    vector<vector<string>> allPalindromicPerms(string S) {
    vector<vector<string>> ans;
    vector<string> output;
    solve(S ,ans , output);
    
    return ans;
    
    
    }
};


*/