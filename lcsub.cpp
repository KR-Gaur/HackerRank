#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>

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
void display_subs(int **a,int r,int c,string s1,string part)
{
	//cout<<endl;
	int cr = a[r][c];
	//cout<<"("<<r<<","<<c<<")";
	if(a[r][c] !=0)
	{
	if(cr == a[r-1][c])
	{
		display_subs(a,r-1,c,s1,part);
		
	}
	if(cr==a[r][c-1])
	{
		display_subs(a,r,c-1,s1,part);
	}
	if(cr!=a[r-1][c] && cr !=a[r][c-1])
	{
		part = s1[c] + part ;
		//cout<<part<<endl;
		display_subs(a,r-1,c-1,s1,part);
		//cout<<s1[c];
	}
	
	}
	else
	{
		//reverse(part.begin(),part.end());
		cout<<endl;
		cout<<part;
	}
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
	
	cout<<len1;
	cout<<len2;
	
	int **a= new int* [len2+1];
	
	for(int i=0;i<=len2;i++)									//two dimensional array , l2 rows  and l1 columns
	{
		*(a+i) = new int[len1+1];
		a[i][0]=0;
		a[0][i]=0;
	}
	
	cout<<"mmm\n";
	
	
	for(int i=1; i < len2; i++)
	for(int j=1;j< len1;j++)
	{
		//cout<<s[i]<<"---"<<s[j]<<endl;
		if( s2[i] == s1[j]   )
			a[i][j] = 1 + a[i-1][j-1];
			
		else
		{
			a[i][j] = max(a[i-1][j],a[i][j-1]);
		}
		
		//prin(a,len2,len1);	
	}
	
	//cout<<a[sw-1][kp];	
	prin(a,len2,len1);
	string part="";
	display_subs(a,len2-1,len1-1,s1,part);
	return 0;
}
