#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>
using namespace std;


void pn(char s[],int t,int num,int nod){
  
  if(nod==1) return;
  for(int j=0;j<=9;j++)
  {
    s[t]=48+j;
    //cout<<atoi(s)<<endl;
    if(atoi(s)<=num)
    {
      cout<<atoi(s)<<endl;
      //cout<<"*";
      pn(s,t+1,num,nod-1);
    }
    s[t+1]='\0';
  }
}
void lexicographicalOrder(int num){
	// Write your code here
  int noOfDigits = 0;
  int numCopy = num;
  
  while(numCopy!=0)
  {
    noOfDigits++;
    numCopy=numCopy/10;
  }
  cout<<" digits :"<<noOfDigits<<endl;
 char *s = new char[5];
 for(int i=1;i<=9;i++)
 {
  // cout<<i<<endl;
   s[0]=48+i;
   s[1]='\0';
   if(atoi(s)<=num)
   cout<<atoi(s)<<endl;
   pn(s,1,num,noOfDigits);
 }
 
}

int main()
{
	lexicographicalOrder(100); 
	return 0;	
}
