#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(long z)
{
    if(z==1 || z<0)
        return 0;
    for(auto i =2;i<=(z/2)+2;i++)
        if(z%i==0 && z!=i)
            return 0;
    return 1;
}
void sieve(vector <bool>s)
{
    for(auto i=2;i<=sqrt(10000000);i++)
    {
        if(s[i]==true)
        {
            for(auto j=2*i;j<=10000000;j=j+i)
            {
                s[j]=false;                    
            }
        }
    }
}
    int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int a,b,c,q;
    vector <bool>s(10000001,true);
        s[1]=false;
         for(auto i=2;i<=sqrt(10000000);i++)
    {
        if(s[i]==true)
        {
            for(auto j=2*i;j<=10000000;j=j+i)
            {
                s[j]=false;                    
            }
        }
    }
    //sieve(s);
    //long p=0;
    long q1,count=0;
    cin>>a>>b>>c;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>q1;
        
        cout<<endl<<q1;	
        for(long j=0;j<=q1;j++)
        {
            long z = a*j*j + b*j + c;
           // cout<<s[z]<<"->";
                if(z>0&&s[z] )
                {
                   count++;
               //     cout<<z<<",";
                }  
        }
        cout<<count<<endl;
        //	p=q1+1;
    }
  /*  for(int i=2;i<=100;i++)
	if(s[i]==true)
	cout<<i<<" ,";*/
    return 0;
}

