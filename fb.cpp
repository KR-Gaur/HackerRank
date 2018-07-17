#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int numways(string s,int i,int lo)
{
	if(i>s.length()-1)
	return 0;
	
	else if(i==s.length()-1)
	{	/*cout<<"\n"<<i<<">><<"<<lo;*/	return 1;	}
	
	else
	{	
		int one = numways(s,i+1,-1);		
		int two = stoi(s.substr(i,2));
			
			//cout<<"\n right"<<two;
		if(two <= 26)
		 {	
		 	
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
	return 0;
}
