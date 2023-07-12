#include<bits/stdc++.h>
using namespace std;

#include <unordered_map>
int getLengthofLongestSubstring(string s, int k)  
{
int ans = -1;
int left_ptr = 0 ;
unordered_map <char , int> mp;
for ( int right_ptr = 0 ; right_ptr< s.size(); right_ptr++)
{
 mp[s[right_ptr]]++;
 if (mp.size() <= k)
 {
  ans = max ( ans , (right_ptr-left_ptr)+1);
 }
 else if ( mp.size() > k)
 {
  while ( mp.size() >k  && right_ptr >left_ptr )
  {
   if ( mp[s[left_ptr]] == 1 )
    mp.erase(s[left_ptr]);
   else  
    mp[s[left_ptr]]--;
   left_ptr++;
  }
 }
 ans = max ( ans , (right_ptr-left_ptr)+1);
}
return ans;
}











int main(){
    
    return 0;
}