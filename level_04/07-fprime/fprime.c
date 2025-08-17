#include <stdio.h>
#include <stdlib.h>
int main (int argc, char **argv){
if (argc != 2){
printf("\n");
return 0;
}

int n = atoi(argv[1]);
if (n == 1){
printf("1\n");
return 0;}

int i = 2;
int first = 1;
while (i*i <= n){
while (n % i == 0){
if (!first)
printf("*");
printf("%d", i);
n /= i;
first = 0;
}
i++;
}
if(n>1){
if (!first)
printf("*");
printf("%d", n);
}
printf("\n");
return 0;
}
