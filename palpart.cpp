#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>


using namespace std;

int x;

bool pal(string s,int j,int l)
{
	//s[1]='2';cout<<"--"<<s<<endl;return x;
	string s1 = s.substr(j,l);	
	string s2 = s.substr(j,l);
	reverse(s2.begin(),s2.end());
	if(s1==s2)
	return true;
	
 return false;
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
	int minn;
	string s;
	cin>>s;
	//cout<<n;
	int len=s.length();
	minn=len+1;
	int **a= new int* [s.length()];
	
	for(int i=0;i<s.length();i++)
	{
		*(a+i) = new int[s.length()];
		a[i][i] = 0;
	}
	//pal(s);
	for(int i=1;i<len;i++)
	for(int j=0;j<len;j=j+i)
	{
	
		if (pal(s,j,j+i)==true)
			{ 
				a[j][j+i] = 0;
				prin(a,len,len);
			}
		
		else
		{	
			int k=j;
			minn = 1 + a[j][k] + a[k+1][j+i];
			for(;k<j+i;k++)
			{
			
				minn = min(minn,1 + a[j][k] + a[k+1][j+i]);
			
			}
			a[j][j+i]=minn;	
			prin(a,len,len);
		}
	}
	
	//func(s)=5;
	//cout<< x;
	//cout<<s;
	cout<<a[len-1][len-1];
	return 0;
}
