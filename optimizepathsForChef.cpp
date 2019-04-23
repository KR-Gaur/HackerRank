#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#define modd 1000000007
#define ll long long int
using namespace std;

int main(){
	
	ll test;
	ll arr[100003][103];
	ll pathLengths[100003];
	ll r,c;
	ll numPaths;
	ll i,j;
	
	cin>>test;
	for(int tt=0;tt<test;tt++){
	
	memset(arr,0,sizeof(arr));
		
		for(i=0;i<=r;i++){
			pathLengths[i]=0;
		}
	
		cin>> numPaths;
	
		r=numPaths-1;
	
		for(i=0;i<=r;i++){
			cin>>pathLengths[i];
		}
		c = pathLengths[numPaths-1];
	
        
		for( i=0;i<=r;i++)
			arr[i][0] = 1;		
		for(j=0;j<=c;j++) if(j<=pathLengths[0]) arr[0][j] = 1;
		
		arr[0][0] = 1;
		
		for(i=1;i<=r;i++){
		for(j=1;j<=pathLengths[i];j++) {
		//if( j <= pathLengths[i] ) 
			arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % modd;
		}
	}
	/*for(i=r;i>=0;i--){
			for(j=0;j<=numPaths-1;j++) cout<<arr[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;*/
	cout<<arr[r][c]<<endl;
	
	}
	return 0;
}
