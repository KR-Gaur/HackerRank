#include <stdio.h>

struct p

{

int x;

char y;

};

void foo(struct p* );

int main()

{

typedef struct p* q;

struct p p1[ ] = {1, 92, 3, 94, 5, 96};

//foo(p1);
for(int i =0 ;i<6;i++)
printf("%d,%c\n",p1[i].x,p1[i].y);
return 0;

}


