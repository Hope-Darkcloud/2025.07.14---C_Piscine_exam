#include <unistd.h>
int main (int argc, char **argv){
    int i = 0;
    int end;
    
    if (argc == 2){
        while(argv[1][i]){
            i++;
        }
        i--;
        while(i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t')){
            i--;
        }
              if(i < 0){
            write(1, "\n", 1);
            return 0;
        }
              
              end = i;
              
              while(i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t'){
            i--;
        }
              i++;
              while(i <= end){
            write(1, &argv[1][i], 1);
            i++;
        }
            }

    write(1, "\n", 1);
    return 0;
    
}
