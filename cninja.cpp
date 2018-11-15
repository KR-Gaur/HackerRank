#include<iostream>
using namespace std;

void printfun(int,int,string);
void printWellFormedParanthesis(int n){
    // Write your code here
  printfun(n,n,"");
}

void printfun(int o,int c,string s)
{
	//cout<<"s"<<s<<endl;
  if(o==0 && c==0) { cout<<s<<endl; }
  
  if(o<0) return;
  if(o>c) return ;
  
  
  printfun(o-1,c,s+"(");
  
  printfun(o,c-1,s+")");
  //cout<<endl;
  
}

int main()
{
	printWellFormedParanthesis(3);
	return 0;
}
