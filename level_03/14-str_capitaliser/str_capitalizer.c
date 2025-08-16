#include <unistd.h>
int is_space(char c){
    return (c == ' ' || c == '\t');
    
}

int is_alpha(char c){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    
}

int main (int argc, char **argv){
    if (argc == 1){
        write(1, "\n", 1);
        return 0;}
    
    int i, j;
    j = 1;
    while(j < argc){
        i = 0;
        while(argv[j][i]){
            char c = argv[j][i];
            if(is_alpha(c)){
                if (i == 0 || is_space(argv[j][i-1])){
                    if (c >= 'a' && c <='z')
                        c = c - 32;
                }else {
                    if (c >= 'A' && c <= 'Z'){
                        c = c + 32;}
                }
            }
            write(1, &c, 1);
            i++;
            
        }
        write(1, "\n", 1);
        j++;
    }
    return 0;
    
}

