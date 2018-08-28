#include<iostream>

#include<unordered_map>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
 
 string s;
 
 cin>>s;
 set <string >sett;
 for(int i=0;i<s.size();i++)
 {
 	string h =s;
 	char f =s[i];
     h.erase(remove(h.begin(),h.end(),f),h.end());
     cout<<h<<endl;
       
       sett.insert(h);    
     
 }
  set <string> :: iterator itr=sett.begin();
 cout<<"\nanswer "<<*itr;
 
 
 return 0;   
}
/*
// Sample code to perform I/O:
#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,q,l,r;
	int count=0;
	char m[100];
	char *a = (char*)malloc(sizeof(char)*(n+2));
	int sto[100];
	scanf("%d%d", &n,&q);              			// Reading input from STDIN
	//  printf("\nInput number is %s.\n");
	//printf("Input number is %d.\n", num);       // Writing output to STDOUT
	for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
   // printf("\nInput number is %s.\n");
    for(int i=1;i<=q;i++)
    {
        count =0;
        scanf("%d", &l);
        scanf("%d", &r);
        int qu=0;
        for(int k=l;k<=r;k++)
            {
                int num = a[k],rem;
                int j =0;
                while(num!=0)
                {
                    sto[j] = num% 2;
                    qu = num /2;
                    num = num /2;
                    j++;
                     
                }
                sto[j]=qu;
              /*  for(int bb=0;bb<j;bb++)
                printf("%d",sto[bb]);
                printf(" ");
                
                for(int bb=0;bb<j;bb++)
                {
                    if(sto[bb]==1 && sto[bb+1]==1)
                        { count++; break;}
                }
                
                
            }
            printf("%d\n",count);
           
    }
    
//	itoa(num,num,2);
//	printf("\nInput number is %s.\n", m); 
	
}

// Warning: Printing unwanted or -formatted data to output will cause the test cases to fail


// Write your code here
*/
