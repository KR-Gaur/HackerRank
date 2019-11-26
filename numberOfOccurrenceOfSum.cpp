#include<iostream>

using namespace std;

void fun(int arr[],int i,int csum,int sum,int &count){
	if(csum + arr[i] > sum ) return;
	if(csum + arr[i] == sum)  count++; //cout<<"found at "<<arr[i]<<endl;	
	if(i+1 < 4 ) {
		fun(arr,i+1,csum + arr[i],sum,count);
		fun(arr,i+1,csum,sum,count);	
	}
}
int main(){
	int arr[] = {10, 5, 3, 2}; int count =0;
	fun(arr,0,0,15,count);
	cout<<count<<endl;
	return 0;	
}
