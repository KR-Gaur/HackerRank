/*
	Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?
	
sample input

4
9 6 5 1
11

sample output
2

*/

#include<iostream>


using namespace std;
//int a[] ={2,3,5};
int *a;
int n;
int state=999;
void fun(int sum,int sum_req,int s)
{
	if(sum>sum_req)
	return;
	else if(sum==sum_req)
	{
		if(s <state)
		state =s ;
		return; 
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			fun(sum+a[i],sum_req,s+1);
		}
	}
}

int main()
{
	int sum_req;
	cin>>n;
	a = new int[n];
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	cin>>sum_req;
	cout<<endl;
	//for(int i=0;i<n;i++)
	//cout<<a[i];
	fun(0,sum_req,0);
	cout<<state;
	return 0;
}




