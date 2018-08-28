#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int x,y,x3,y3,x2,y2;
	
	double r = 12.3;
	x=12;
	y=13;
	while(y<=1000)
	{
		r = y*y+144;
		r=sqrt(r);
		if((int)r==r)
		cout<<y<<","<<r<<endl;
		y++;
	}
	cout<<"r";
	return 0;
}
