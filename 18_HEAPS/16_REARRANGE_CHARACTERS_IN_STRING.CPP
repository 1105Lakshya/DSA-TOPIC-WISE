/*
Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Example 1:

Input : str = "geeksforgeeks"
Output: 1
Explanation: All the repeated characters of the
given string can be rearranged so that no 
adjacent characters in the string is equal.
Any correct rearrangement will show a output
of 1.
Example 2:

Input : str = "bbbbb"
Output: 0
Explanation: Repeated characters in the string
cannot be rearranged such that there should not
be any adjacent repeated character.
Your task :
You don't have to read input or print anything. Your task is to complete the functionrearrangeString() which takes the string as input and returns the modified string. If the string cannot be modified return "-1".
Note:The generatedoutput is 1 if the string is successfully rearranged and is 0 if rearranging is not possible.
 
Expected Time Complexity : O(NlogN), N = length of String
Expected Auxiliary Space : O(number of english alphabets)
 
Constraints :
1 <= length of string <= 104


*/



//ALGO
/*
first we will make a map storing the frequency of each character 
if frequency of any character is greater than n/2 (n is size of the string)  in case of even and (n/2 + 1 ) in case of odd  then there is no
way to arrange the characters so that no two are adjacent  
now we will insert the two maximum occuring characters in the answer string and will repeat the process until the string has only one or zero
elements left  for this we will be using a priority queue that will prioritize on the basis of count of characters we will pop the two elements
and will only push them back if theit frequency will be greater than zero after decrementing one 



*/


//solution

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends















 
class Solution
{
    public:
    string rearrangeString(string str)
    {
        unordered_map<char ,int> mp;
        for(auto it: str){
            mp[it]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto it: mp){
            if(it.second >( str.size()+1)/2){ //if this is the condition then in no case there will be no adjacent character
            return "-1";
            }
            
            pq.push({it.second ,it.first});
        }
        string ans="";
        while(pq.size()>=2){
            pair<int ,char > p1=pq.top();
            pq.pop();
            pair<int ,char > p2=pq.top();
            pq.pop();
            ans=ans+p1.second;
            ans=ans+p2.second;
            
            if(p1.first-1 >0 ){
                pq.push({p1.first-1 , p1.second});
            }
            if(p2.first-1 >0 ){
                pq.push({p2.first-1 , p2.second});
            }
        }
        
        
        
        
        if(pq.size() >0){
            pair<int ,char > p=pq.top();
            ans=ans+p.second;
        }
        
        
        return ans;
    }
    
};

//OTHER approach
class Solution2
{
    public:
    string reorganizeString(string s)
    {
        // Step-1: Store the characters count in 'm'.
        //         And also keep track of most frequent character.
        int mostFreq = 0;
        vector<int> m(256, 0);
        for (char c: s) 
        {
            if(++m[c] > m[mostFreq])
                mostFreq = c;
        }
        
        // Step-2: If the most frequent character occurs more than half of the actual string size,
        //         it means that it is not possible to reorganize the input string. Return here.
        //         Otherwise, fill this mostFreq character in alternative even index of the result string (we can do it in-place).
        if (2*m[mostFreq] - 1 > s.size())
            return "";
        
        int i = 0;
        while (m[mostFreq] > 0)
        {
            s[i] = (char)mostFreq;
            m[mostFreq]--;
            i = i+2;            
        }
        
        // In step-2 above, why are we first filling the result array with mostFreq character first?
        // Why can't we just remove the above while loop and let the below loop handle everything?
        // This is because of some special cases like "vvvlo". If we leave everything to the below while loop,
        // then the result would be "lvovv", because that will start the loop with 'l', then 'o' and then finally 'v'.
        // By the time, the loop reached 'v', we already ran out of space and have to keep 'v's next to each other, which will void
        // the original condition.
        
        // Step-3: Fill each of the character in alternative index.
        //         Remember that 'i' is still an even number and we first fill even indices.
        //         Once, they are over, then we start filling odd indices starting from i=1
        for (int j=0; j<256; j++)
        {
            while (m[j] > 0)
            {
                if (i>=s.size())
                    i = 1;
                s[i] = (char)j;
                m[j]--;
                i = i+2;
            }
        }
        
        // Step-4: Done
        return s;
    }
};























// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends