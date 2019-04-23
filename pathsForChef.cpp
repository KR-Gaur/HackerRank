#include<iostream>
#include<math.h>
#define modd 10000007

using namespace std;


int fun(int r,int c,int **arr,int *pathLengths){
	if(r<0 || c<0) return 0;
	if(r == 0 && c == 0 ) return 1;
	if(arr[r][c] != -1 ) { return arr[r][c];};
	//cout<<"("<<r<<" "<<c<<")"<<endl;

	int down = 0;
	if(pathLengths[r-1] >= pathLengths[r] || c <= pathLengths[r-1] )down = fun(r-1,c,arr,pathLengths) % modd;
	
	int left = fun(r,c-1,arr,pathLengths) % modd;
	
	arr[r][c] = (left + down) % modd;
	return arr[r][c];
}

int main(){

	int test;
	int **arr=NULL;
	int *pathLengths=NULL;
	cin>>test;
	
	for(int tt=0;tt<test;tt++){
	
		
		int r,c;
		int numPaths;
		cin>> numPaths;
	
		pathLengths = new int[numPaths];
	
		r=numPaths-1;
	
		for(int i=0;i<=r;i++){
			cin>>pathLengths[i];
		}
		//cout<<"\n Path des : "<<pathLengths[numPaths-1]<<endl;	
		c = pathLengths[numPaths-1];
	
		//cout<<endl<<" r : "<<r<<" c : "<<c<<endl;
		arr = new int*[r+1];
	
		for(int i=0;i<=r;i++){
			arr[i] = new int[c];
			for(int j=0;j<=c;j++) arr[i][j] = -1;
		}
		/*
		for(int i=r;i>=0;i--){
			for(int j=0;j<=c;j++) cout<<arr[i][j]<<" ";
			cout<<" pathLength : "<<pathLengths[i];
			cout<<endl;
		}
	
		cout<<"\nPaths : "<<fun(r, c, arr,pathLengths);
	
		cout<<endl;
	
		for(int i=r;i>=0;i--){
			for(int j=0;j<=c;j++) cout<<arr[i][j]<<" ";
			cout<<endl;
		}
		*/
		
		cout<<fun(r, c, arr,pathLengths) % modd;cout<<endl;
		delete[] pathLengths;
		
		for(int i=0;i<=r;i++){
			delete[] arr[i];
		}
		delete[] arr;
	}
	return 0;
}
