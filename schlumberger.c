#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int processArray(int array[], int len) {

  
    for(int i=0;i<len;i++)
   {
   //     printf("%d\n", array[i]);
   }
   
   int j=0;
   int it=0;
   int *count =(int *)malloc (sizeof(int)*len);
   int *index =(int *)malloc (sizeof(int)*len);
   
   for(int i=0;i<len;i++)
   {
       
       if(array[i] %2 ==0)
       {
           it++;
       }
       else if(it!=0)
       {
           count[j] =it;
           index[j] = i-1;
           it =0;
           j++;
       }
   }
   if(array[len-1]%2==0)
   {
           count[j] =it;
           index[j] = len-1;
           it =0;
           j++;
   }
   //printf("\n");
   for(int i=0;i<j;i++)
   {
 //        printf("%d  ", count[i]);
  //      printf("%d\n", index[i]);
   }
   int max = -1;
   int ind ;
   for(int i=0;i<j;i++)
   {
       if(count[i]>max)
       {
           max = count[i];
           ind = index[i];
       }
   }
  // printf("\n%d %d\n",max,ind);
   int min = 999999;
   for(int i=ind;max>0;max--)
   {
       if(array[i]<min)
       {
           min = array[i];
       }
       
       i--;
   }
//   printf("\n%d\n",min);
if(min==999999)
  return 0;
  
  return min;
}

int main() {
  int *array;
  int len = 0, maxsize = 1024, i, input;
  int result;
  array = (int *)malloc(maxsize*sizeof(int));
  while(scanf("%d", &input) == 1) {
    if (input < 0) break; /* Stop when a negative number is entered */
    array[len++] = input;
    if (len == maxsize) { /* array is full. increase size */
      maxsize *= 2;
      array = (int *)realloc(array, maxsize*sizeof(int));
    }
  }
  result = processArray(array, len);
  printf("%d\n", result);
  return 0;
}
/*
input
10
62
36
624
303
645
262
122
662
122
-1
*/

