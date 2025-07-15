#include <unistd.h>
int main (void){
    int i = 0;
    char c;
    while(i < 26){
        c = 'z' - i;
        if(i % 2 == 1)
        {c = c - 32;
        } write(1,&c, 1);
        i++;
    }
    write(1, "\n", 1);
    return 0;
    
}


