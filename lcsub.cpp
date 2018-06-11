#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>


using namespace std;
int max( int a , int b)
{
	if (a>b)
	return a;
	
	return b;
}
void prin(int **a,int r,int c)
{
	for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j=j+1)
			cout<<a[i][j];
			
			cout<<endl;
		}
		
		cout<<endl;
}

int main()
{
	string s;
	
	cin>>s;
	string s1=" ";
	s1 = s1 + s;
	
	cin>>s;
	string s2=" ";
	s2 = s2 + s;
	
	int len1 = s1.length();
	int len2 = s2.length();
	
	
	
	int **a= new int* [len2+1];
	
	for(int i=0;i<=len2;i++)
	{
		*(a+i) = new int[len1+1];
		a[i][0]=0;
		a[0][i]=0;
	}
	cout<<"mmm\n";
	
	
	for(int i=1; i <= len2; i++)
	for(int j=1;j<=len1;j++)
	{
		//cout<<s[i]<<"---"<<s[j]<<endl;
		if( s1[j] == s2[i] )
			a[i][j] = 1 + a[i-1][j-1];
			
		else
		{
			a[i][j] = max(a[i-1][j],a[i][j-1]);
		}
		
		prin(a,len2,len1);	
	}
	
	//cout<<a[sw-1][kp];	
	prin(a,len2,len1);
	return 0;
}
