#include <unistd.h>
int ft_atoi(char *str){
    int i = 0;
    int num = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
    
}

void ft_putnbr(int n){
    char c;
    if(n >=10)
        ft_putnbr(n/10);
    c = (n % 10) + '0';
    write(1, &c, 1);
    
}

int main (int argc, char **argv){
    if (argc != 2){
        write(1, "\n", 1);
        return 0;
        
    }
    int n = ft_atoi(argv[1]);
    for(int i = 1; i <= 9; i++){
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(n);
        write(1, " = ", 3);
        ft_putnbr(i * n);
        write(1, "\n", 1);
        
    }
    
    return 0;
    
}
