#include <stdio.h>
#include <unistd.h>
int first_str(char c, char *str){
    int i = 0;
    while(str[i]){
        if(str[i] == c)
        {return 1;}
        i++;
        }
    return 0;
    
}

int control_str(char *str, char c, int index){
    int i = 0;
    while(i < index){
        if (str[i] == c) {return 1;}
        i++;}
    return 0;
    
}

int main(int argc, char **argv){
    int i = 0;
    if(argc == 3){
        while (argv[1][i]){
            if(first_str(argv[1][i], argv[2]) && !control_str(argv[1], argv[1][i], i)){
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
    
}
