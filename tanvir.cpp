#include<bits/stdc++.h>
#include<math.h>

using namespace std;
long int arr[1000000]={0};

long rec(int a){
  long double p=sqrt(a);
 // cout<<"a="<<a<<" "<<endl;
  if(a==1) return 0;
  if(arr[a]!=0) return arr[a];
  
  
  if(modf(p,&p)==0.00)
  {	
    arr[a]=1+rec(p);
  	return arr[a];
  }
  
  else
  {
   	arr[a]=1+rec(a-1); 
    return arr[a];
  } 
}
int main()
{
    long n,a;
  //arr[1]=0;
  	cin>>n;
  for(long i=0;i<n;i++){
    cin>>a;
    cout<<rec(a)<<endl;
 //   cout<<endl;
  // for(long i=0;i<10;i++){
  //  cout<<" "<<i<<" "<<arr[i]<<endl;
  }
  }
 /* cout<<endl;
   for(long i=0;i<10;i++){
    cout<<" "<<i<<" "<<arr[i]<<endl;
  }*/
	return 0;
}

