#include<iostream>
#include<string>
#include<algorithm>            //FOR SORT FUNCTION 

using namespace std;

int main(){
    // string str;
    // cin>>str;        //no space in between input
    // cout<<str<<endl;   
    // string str1(5,'d');
    // cout<<str1<<endl;

    // string str2 ="apnikakshaa";
    // string str;
    // getline(cin,str);                         //use to input space separated strings
    // cout<<str<<endl;
    


    // APPENDING
    string s1="fami";
    string s2="ly";
    // s1.append(s2);
        // or
    s1=s1+s2;
    cout<<s1<<endl;

    s1.clear();       //clear kardiyyaa
    if(s1.compare(s2)==0)
cout<<"strings are equal"<<endl;
else
cout<<"they are not equal"<<endl;
s1.empty();                    //batata hai ki string empty hai ki nahhhiii  agar empty hogii toh zero return karregaaaa


//ERASE                 kuch bichh ke shabd hattadegga or uskii jaggaa jo agge shabd honge unko laaadeggaa
string str="nincompop";

str.erase(3,4);              //s1.erase(adress from where deletion is began , no of elements u want to delete)
cout << str;
cout<<str.find("poo")<<endl;

//FINDING IF PRESENT OR NOT
for(int i=0;i<5;i++){
    cout<<endl;
}
string deepika="lakshyaiscuteifhedoesnotmasturbate";
auto it=deepika.find("masturbate");
// auto it=deepika.find("deepika");
if(it!=string:: npos ){
    cout<<deepika.substr(it,10);
for(int i=0;i<5;i++){
    cout<<endl;
}
}






//INSERTING THE STRINGS
str.insert(2,"loda");
cout<<str<<endl;

//FINDING THE LENGTH OF STRING 
cout<<str.size()<<endl;
cout<<str.length()<<endl;


//getting substring
string s= str.substr(3,5);          //str.substr(index,jitnne element chhiye substring mei)


//string to integer

string nums="1233";
int x=stoi(nums);                         //string to integer 


//integer to string
cout<<to_string(10)+"2";          //output is  12332

//   SORTING STRINGS 
sort(s1.begin(),s1.end());                         //sorted the string

//COUNTING TO SINGLE DIGIT                 // CHARACTER BY CHARACTER TRAVERSAL
int count =234;
int ansindex=0;
char chars[20];
string cnt=to_string(count);
for(char ch: cnt)    //for(char ch belongs to count )
{
   chars[ansindex++]=ch; 
}


//CHECKS IF ENTERED CHARACTER IS PUNCTION   
if(ispunct('3')){
cout<<"deepika doggy";
}
    return 0;
}




//NOTE::::: IN ARRAY ROTATION QUESTION DO THINK ABOUT CONCATINATING THE ARRAY  AND THEN TRAVERSINGGGGG