#include<iostream>
using namespace std;

void bb();

int main()
{
	void fun();
	
	
	fun();
	bb();
	return 0;
}
void bb()
{
	fun();
}
void fun()
{
		cout<<"hello";
}



