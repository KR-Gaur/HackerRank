#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int isprime(int num)
{
	for(int i =2;i<=num;i++)
	{
		if(num%i==0&& num!=i)
		return false;
	}
	return true;
}
void sieve(int num)
{
	vector<bool> s(num+1,true);
	//int s[num+1] ={};
	cout<<"\nUsing Seive  ";
	for(int i=2;i<=sqrt(num);i++)
	{
		
		for(int j=2*i;j<=num;j=j+i)
		{
			if(j%i==0)
			{	
				s[j]=false;
				//cout<<"false"<<j;
			}	
		}
	}
	
	for(int i=2;i<=num;i++)
	if(s[i]==true)
	cout<<i<<" ,";
	
}
void sieve2(int num)
{
	vector<bool> s(10000001,true);
	
    for(int i=2;i<=sqrt(10000000);i++)
    {
        if(s[i]==true)
        {
            for(int j=2*i;j<=10000000;j=j+i)
            {
                s[j]=false;                    
            }
        }
    }
    
    for(int i=2;i<=num;i++)
	if(s[i]==true)
	cout<<i<<" ,";
}
int main()
{
	int num;
	
	cin>>num;
	
	
	cout<<"Primes Upto "<<num<<endl;
	
	sieve(num);
	
	cout<<"\nNaive  ";
	
	while(num>=2)
	if(isprime(num--))
	{
		cout<<num+1<<" ,";
	}
	//else
	//cout<<"It is not a prime number";
	
	
	return 0;
}
