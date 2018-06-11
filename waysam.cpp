#include<iostream>
//#include<stdio.h>

using namespace std;
long unsigned int *arr;
long unsigned int  n_ways(int n,int x[],int s)
{
	//cout<<n;
	
	if(n== 1 || n== 0)
	return 1;
		
	else if (arr[n]!=-1)
	return arr[n];
	
	else
	{
		int total=0;
		 for(int j=0; j<s; j++)
		 {
		 	if(n>=x[j])
		 		{
		 			 total=total+n_ways(n-x[j],x,s);
		 		}
		 }		 
		 arr[n]=total;
		 return arr[n];		 
	}
}

int main()
{
	int n;
	int x[]={1,3,5};
	cin>>n;
	arr = new long unsigned int [n+1];
	
	arr[0]=1;
	arr[1]=1;
	
	for(int i=2; i<=n; i++)
	arr[i]=-1;
	
	
	cout<<n_ways(n,x,sizeof(x)/4);
	return 0;
}
