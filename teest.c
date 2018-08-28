#include <stdio.h>

int main()

{

char c;

int i = 0;

FILE *file;

file = fopen("test.txt", "w+");

fprintf(file, "%c", 'a');

fprintf(file, "%c", -1);

fprintf(file, "%c", 'b');

fclose(file);

file = fopen("test.txt", "r");

while ((c = fgetc(file)) != -1)

printf("%c\n", c);

return 0;

}
