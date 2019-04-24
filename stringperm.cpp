#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int getValue(int count[],int nodigits){

	for(int i=0; i<nodigits; i++) {
		if(count[i] != 0) 
			return i;
	}
	return -2;				// -2 when all are zero
}

int fun(int num[],int temp[],int count[],int pos,int nodigits,int N){

	if(pos <= nodigits)
	{
		int notAllZeros = getValue(count,nodigits);	
		
		if(notAllZeros == -2) {			
			//for(int i=0; i<nodigits; i++) cout<<temp[i]<<" ";
			//cout<<endl;
			int sum =0,number=0;
			
			for(int i=nodigits-1; i>=0; i--){
				number = temp[i] * pow(10,nodigits-i-1);
				sum = sum + number;
			}		 

			//cout<<sum<<endl;
			if(sum%N==0){
			cout<<sum<<endl;
			return -3;}
		}
	
	
		for(int i=notAllZeros;i<nodigits;i++){
			temp[pos] = num[i];
			count[i]--;
			int ret = fun(num,temp,count,pos+1,nodigits,N);
			if(ret == -3) return -3;
			count[i]++;	
		}
			
	return -1;		
			
	}
	
}

int main(){
	
	//vector<int>num;
	int i,N;
	int num[10],temp[10],count[10];
	int t;
	cin>>t;
	while(t--){
		memset(num,0,sizeof(num));
		memset(temp,0,sizeof(temp));
		for(i=0;i<10;i++) count[i]=1;
		/*for(i=0;i<10;i++) {cout<<num[i]<<" "; count[i]=1;}
		cout<<endl;
		for(i=0;i<10;i++) cout<<count[i]<<" ";
		cout<<endl;
		for(i=0;i<10;i++) cout<<temp[i]<<" ";
		
		cout<<endl;*/
		int nodigits,input;
		cin>>nodigits;
		cin>>N;
		for(i=0;i<nodigits;i++){
			cin>>input;
		//	num.push_back(input);
			num[i] = input;
		}
	
		//for(i=0;i<10;i++) cout<<num[i]<<" ";
	
		//cout<<endl<<"****"<<endl;
		int d = fun(num,temp,count,0,nodigits,N);
		if(d==-1) cout<<d; 
	}
	return 0;
}
