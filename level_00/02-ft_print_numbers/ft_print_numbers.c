#include <unistd.h>
void ft_print_numbers(void){
char c = '0';
while(c <= '9'){
write(1, &c, 1);
c++;}
write(1, "\n", 1);
}
int main(){ft_print_numbers();}
