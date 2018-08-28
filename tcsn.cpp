/*Count the number of pairs in integer array whose sum equals given sum (all elements are unique).

Example:

Sum =10,

No.of array elements =9 

Array elements are 0 2 5 7 4 6 10 20 -10

Result is 3 [(0, 10), (4, 6), (20, -10)]
*/


#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
	int n;
	int find,count=0,sum;
	cout<<"sum ";cin>>sum;
	cout<<"No.of array elements ";cin>>n;
	
	vector<int> a(n);
	
	for(int i =0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	
	int min = a[0] - 5; 		
	/*for(int i =0;i<n;i++)
	{
		cout<<a[i]<<",";
	}*/
	
	cout<<endl;
	cout<<"[ ";
	for(int i=0;i<((n/2)+1);i++)
	{
	
		find = sum-a[i];
		if(find != (a[i]))
		{
			if(binary_search(a.begin(),a.end(),find))
			{	
				cout<<"("<<a[i]<<", "<<find<<")";
				a[i] = min;
				count++;
			}
		}
		
		
	}
	cout<<" ]";
	cout<<endl<<"count "<<count<<endl;
	/*for(int i =0;i<n;i++)
	{
		cout<<a[i]<<",";
	}*/
	return 0;
}
