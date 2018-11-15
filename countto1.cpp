
#include<iostream>
using namespace std;

int countStepsTo1(int n){

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     */
 	int nby2 =600,nby3=600;int n_1;//=n-1;
  	if(n==1) {//cout<< 0;
              return 0;}
  	
  	if(n%2==0)	{
      nby2=1+countStepsTo1(n/2);
    }
  	 if(n%3==0)	{
      nby3=1+countStepsTo1(n/3);
    }
  //if(n-1<nby3 && n-1 <nby2)
  	n_1 =1+countStepsTo1(n-1);
 // 	cout<<n	<<endl<<"nby2 :"<<nby2<<endl<<"nby3 :"<<nby3<<endl<<"n-1 :"<<n_1<<endl;
	int c = (nby2 < nby3)?(nby2<n_1? c=nby2:c= n_1):(nby3<n_1?c= nby3:c= n_1);
 // 	cout<<c<<endl;
 //		cout<<"c :"<<c<<endl;
 	return c; 	
 
}


int main()
{
	cout<<countStepsTo1(11);
	return 0;
}
