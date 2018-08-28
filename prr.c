#include<stdio.h>

int main()
{
	char *p = "I am a MITian";
	printf("%s",p);
	
	char *v = "new";
	p = v;
	printf("%s",p);
	
	return 0;
}
