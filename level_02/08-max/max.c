#include <stdio.h>
int	max(int* tab, unsigned int len){
int max_value;
unsigned int i;
if (len == 0){
return 0;}
max_value = tab[0];
i = 1;
while(i < len){
if(max_value < tab[i]){
max_value = tab[i];
}
i++;
} 
return max_value;
}

int main (void){
int arr [] = {1, -55, 34, 308, 35};
printf("%d\n", max(arr , 5));
printf("%d\n", max(arr , 0));
return 0;
}
