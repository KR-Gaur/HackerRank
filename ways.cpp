#include<iostream>
//#include<stdio.h>

using namespace std;
long unsigned int *arr;
long unsigned int  n_ways( int n)
{
	if(n<=0)
	return 0;
	
	if(n==1)
	return 1;
	
	else if(n==2)
	return 2;
	
	else if (arr[n]!=-1)
	return arr[n];
	
	else
	{
		 
		 arr[n-1]=n_ways(n-1);
		 arr[n-2]=n_ways(n-2);
		 
		 return arr[n-1]+arr[n-2];		 
	}
}

int main()
{
	int n;
	
	cin>>n;
	arr = new long unsigned int [n];
	
	arr[1]=1;
	arr[2]=2;
	
	for(int i=3; i<=n; i++)
	arr[i]=-1;
	
	
	
	cout<<n_ways(n);
	return 0;
}
