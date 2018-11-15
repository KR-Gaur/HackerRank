#include<string.h>
#include<iostream>

using namespace std;
void rec(string mystring,string s,int i,int count)
{
  cout<<"*"<<" "<<i<<" "<<mystring<<endl;  
  if(i==s.length())
  { 
  	if(count==0) cout<<mystring<<endl;
  }
  
  if(s[i]=='(')
  {	
    rec(s,mystring+"(",i+1,count+1);
    rec(s,mystring,i+1,count);
  }
   else rec(s,mystring+")",i+1,count-1);
}
void removeInvalidParentheses(string s){
  rec("",s,0,0);
}

int main(){

removeInvalidParentheses("(()()()");
return 0;
}
