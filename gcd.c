#include<stdio.h>
#include<math.h>

int gcd(int p,int q)
{
 int i,j;
 if(q!=0)
    return gcd(q,p%q);
}
  

int main()
{
int a,b,m=0;

printf("\n Enter two numbers:");
scanf("%d%d",&a,&b);

 m=gcd(a,b);

printf("\n G.C.D of %d and % d is : %d \n",a,b,m);

return 0;
}
