#include <unistd.h>
int ft_putchar(char c){
    return write(1, &c, 1);
    }
int already_seen(char *str, char c, int index){
    int i = 0;
    while(i < index){
        if(str[i] == c){
            return 1;
        }
        i++;
    }
    return 0;
    }



int main (int argc, char **argv){
    int i = 0;
    if (argc == 3){
   while (argv[1][i]){
        if(!already_seen(argv[1], argv[1][i], i))
            ft_putchar(argv[1][i]);
        i++;
            }
   i = 0;
    while(argv[2][i]){
        if(!already_seen(argv[2], argv[2][i], i)){
            int j = 0;
            int found = 0;
            while(argv[1][j]){
                if(argv[1][j] == argv[2][i]){
                    found = 1;
                    break;
                }
                j++;
            }
            if(!found)
                ft_putchar(argv[2][i]);
        }
        i++;
    }
}
write(1, "\n", 1);
return 0;
}
