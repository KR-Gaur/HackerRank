#include<iostream>
#include<vector>
using namespace std;



long long merge(int A[],int l,int mid,int h)
{
	vector<int> 
				
				combined;
	int 
		l_temp = l,
		r_temp= mid+1;
		long long count=0;
			
		while(l_temp!=mid+1 && r_temp!=h+1)
		{
			if(A[l_temp]<=A[r_temp])	
			{
					combined.push_back(A[l_temp]);l_temp++; 
			}
			else	
			{ 
					combined.push_back(A[r_temp]);r_temp++; count=count+mid-l_temp+1;
			}
			
		}
		while(l_temp!=mid+1){	combined.push_back(A[l_temp]);l_temp++; }
		while(r_temp!=h+1){	combined.push_back(A[r_temp]);r_temp++; }
		
		for(int i=l,k=0;i<=h;i++,k++)
		{
			//cout<<combined[i]<<" ";
			A[i] = combined[k];
			//cout<<",at "<<i<<" "<<A[l+i]<<" ";
		}
	//	cout<<endl;
		
	return count;
}

long long mergeSort(int A[],int l,int h)
{
	if (l==h) return 0;
	int mid = (l+h)/2;
	long long left = mergeSort(A,l,mid);
	long long right = mergeSort(A,mid+1,h);
	
	long long now = merge(A,l,mid,h);
	
return left+right+now;	
}


long long solve(int A[], int n)
{
  return mergeSort(A,0,n-1);
}



int main()
{
	int A[] = {
				52244275, 123047899 ,493394237, 922363607, 378906890, 188674257, 222477309, 902683641, 860884025, 339100162};
	//cout<<"\n"<<"l      mid       h";
	cout<<"No of Inversions: "<<solve(A,10);
	//cout<<endl<<A[0]<<" "<<A[1]<<" "<<A[2]<<" "<<A[3]<<" "<<A[18];
	return 0;
}
