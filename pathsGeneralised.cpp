#include<iostream>
using namespace std;

int fun(int r,int c,int **arr){
	if(r<0 || c<0) return 0;
	if(r == 0 && c == 0 ) return 1;
	if(arr[r][c] != -1 ) return arr[r][c];
	
	return arr[r][c] = fun(r-1,c,arr)+fun(r,c-1,arr);
}

int main(){

	int **arr;
	int r,c;
	cin>>r>>c;
	
	arr = new int*[r+1];
	for(int i=0;i<=r;i++){
		arr[i] = new int[c+1];
		for(int j=0;j<=c;j++) arr[i][j]=-1;
	}
	
	/*for(int i=0;i<=r;i++){
		for(int j=0;j<=c;j++) cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	*/
	
	cout<<"\nPaths : "<<fun(r, c, arr);
	
	cout<<endl;
	/*for(int i=r;i>=0;i--){
		for(int j=0;j<=c;j++) cout<<arr[i][j]<<" ";
		cout<<endl;
	}*/
	
	return 0;
}
