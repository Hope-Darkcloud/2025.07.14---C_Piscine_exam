#include <stdio.h>
#include <stdlib.h>
int main (int argc, char **argv){
    if (argc == 4){
        int a = atoi(argv[1]);
        int b = atoi(argv[3]);
        char op = argv[2][0];
        int result = 0;
        if (op == '+'){
            result = a + b;
        }else if(op == '-'){
            result = a - b;
        }else if(op == '*'){
            result = a * b;
        }else if(op == '/'){
            result = a / b;
        }else if(op == '%'){
            result = a % b;}
        printf("%d\n", result);
        }
    else {
        printf("\n");
        }
    return 0;
    
    
}
