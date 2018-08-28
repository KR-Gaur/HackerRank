#include<iostream>
#include<map>
#include <bits/stdc++.h>
#include <unordered_map>



using namespace std;
struct arr
{
	int key,value;
};
int main()
{
	unordered_map <int, int> output;
	int n,a,b;
	struct arr *s,temp;
	unordered_map <int, int> :: iterator itr;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		//output.insert(make_pair(a,b));
		output[a]=b;
	}
	int i=0;
	s = new struct arr[n];
	//int a[] ={ 5, 5, 5, 6, 6, 8, 4, 9};
	for(itr=output.begin(); itr!=output.end();itr++)
	{
		
	//	cout<<itr->first<<" "<<itr->second<<endl;
		cout<<i<<" ";
		s[i].key = itr->first;
		s[i].value = itr->second;
		cout<<s[i].key<<s[i].value;
		i++;
	}
	i--;
cout<<"after copy"<<endl;;
	for(int k=0;k<=i;k++)
		{
			cout<<s[k].key<<" "<<s[k].value<<endl;
		}
		
	for(int j=0;j<i;j++)
	{
		for(int k=0;k<=i-1-j;k++)
		{
			if(s[k].value < s[k+1].value)
			 {	
			 	temp = s[k];
			 	s[k] = s[k+1];
			 	s[k+1] = temp;
			 }
		}
		cout<<endl;
		for(int k=0;k<n;k++)
		{
			cout<<s[k].key<<" "<<s[k].value<<endl;
		}	
	}
	for(int k=0;k<n;k++)
		{
			cout<<s[k].key<<" "<<s[k].value<<endl;
		}	
		
	return 0;
}
