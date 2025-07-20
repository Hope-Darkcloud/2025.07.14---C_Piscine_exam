#include <stdio.h>
void	ft_swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    
}
int main(){
    int x = 25;
    int y = 76;
    ft_swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
