#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;
string arr; 

int numways(string s,int i,int lo)
{
	if(i>s.length()-1)
	return 0;
	
	else if(s[i]=='0')
	return 0;
	
	else if(i==s.length()-1)
	{	//cout<<"\n"<<i<<">><<"<<lo;//cout<<endl<<arr;
		return 1;	}
	
	else
	{	
		//arr +=(char)(s[i]+97);
		if(i+1>s.length()-1)
		 	return 1;
		 	
		int one = numways(s,i+1,-1);
		
		//arr.erase(arr.end()-1);		
		int two = stoi(s.substr(i,2));
			
			
		if(two <= 26)
		 {	
		 	//cout<<"\n right"<<two;
		 	//cout<<endl<<"call"<<i;
		 	if(i+2>s.length()-1)
		 	return one+1;
		 	
		 	return one+numways(s,i+2,1);
		 }
		return one;	 
	}
}

int main()
{
	string s;
	
	cin>>s;
	//int b = stoi(s);
	//cout<<b<<endl;	
	cout<<"Result = 	"<<numways(s,0,0)<<"\n";
	//s.erase(s.end()-1);
	//cout<<s<<endl;
	return 0;
}
