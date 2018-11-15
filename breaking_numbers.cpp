#include<iostream>
#include<vector>
using namespace std;
void rec(int n,int cur,int sum,vector<int> s)
{
  for(int i=cur;i<=n;i++)
  {
  	
    if(sum+i > n) break;
    
    else if(sum+i==n) 
    {	
    	vector<int> temp(s);temp.push_back(i);
    	for(int i=0;i<temp.size();i++)
    	cout<<temp[i]<<" ";
    	
    	cout<<endl;
    	break;	
    }
    else
    {	
    	 vector<int> temp(s);temp.push_back(i);
     	 rec(n,i,sum+i,temp);
    }
  }
}

void printCombination(int n)
{
    //write your code here
    vector<int> s;
    for(int i=1;i<=n;i++)
	{
		s.push_back(i);
		rec(n,i,i,s);
		s.pop_back();
	}
    	
}

int main()
{
	printCombination(4);
	cout<<4;
	return 0;
}

