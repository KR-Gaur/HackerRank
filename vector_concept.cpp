#include<iostream>
#include<vector>

using namespace std;

void printfun(int,int,string,vector<string>*);
//vector <string> strings;

void printfun(int o,int c,string s,vector<string>* strings)
{
	//cout<<"s"<<s<<endl;
  if(o==0 && c==0) { //cout<<s<<endl;
  					 strings->push_back(s); }
  
  if(o<0) return;
  if(o>c) return ;
  
  
  printfun(o-1,c,s+"(",strings);
  
  printfun(o,c-1,s+")",strings);
  //cout<<endl;
  
}

vector<string>* findParenthesis(int n)
{	
	static vector <string> allstrings;
	printfun(3,3,"",&allstrings);
/*	
	for(int it=0;it<allstrings.size();it++){
	cout<<allstrings.at(it)<<endl;
	}
	*/
	return &allstrings;
}
int main()
{
	vector<string> *s;
	s = findParenthesis(3);
	cout<<"\n Returned String"<<endl;
	for(int it=0;it<s->size();it++){
	cout<<s->at(it)<<endl;
	}
	return 0;
}
